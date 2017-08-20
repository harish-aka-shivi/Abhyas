import webapp2
import jinja2
import os
import re
import random
import string
import hashlib
import hmac
from google.appengine.api import memcache
from google.appengine.ext import db
import logging
import time

template_dir = os.path.join(os.path.dirname(__file__),'blog_templates')
jinja_env = jinja2.Environment(loader = jinja2.FileSystemLoader(template_dir),autoescape = True)

#helper function to render string using jinja
def render_str(template, **params):
    t = jinja_env.get_template(template)
    return t.render(params)

#regex for matching username, password,email
USER_RE = re.compile(r"^[a-zA-Z0-9_-]{3,20}$")
def valid_username(username):
    return username and USER_RE.match(username)

PASS_RE = re.compile(r"^.{3,20}$")
def valid_password(password):
    return password and PASS_RE.match(password)

EMAIL_RE  = re.compile(r'^[\S]+@[\S]+\.[\S]+$')
def valid_email(email):
    return not email or EMAIL_RE.match(email)

#Hash secret
SECRET = "whatthehell"
def hash_str(s):
    return hmac.new(SECRET,s).hexdigest()

def make_secure_val(s):
    return "%s|%s" % (s, hash_str(s))

def check_secure_val(h):
    val = h.split("|")[0]
    if h == make_secure_val(val):
        return val
    else:
        return None

def make_salt():
   return "".join(random.choice(string.letters) for x in range(0,5))

def make_pw_hash(name, pw, s = None):
    if not s:
        s = make_salt()
    o = name + pw + s
    return '%s|%s' % (hashlib.sha256(o).hexdigest(),s)

def valid_pw(name, pw, h):
    salt = h.split('|')[1]
    if h == make_pw_hash(name,pw,salt):
        return True
    else:
        return False


# Base class for all the handlers with some utility methods
class Handler(webapp2.RequestHandler):
    def write(self, *a, **kw):
        self.response.out.write(*a,**kw)

    def render_str(self, template, **params):
        return render_str(template,**params)

    def render(self,template,**kw):
        self.write(self.render_str(template,**kw))

    # helper method to wite cookies
    def set_secure_cookie(self, name, val):
        cookie_val = make_secure_val(val)
        self.response.headers.add_header(
            'Set-Cookie',
            '%s=%s; Path=/' % (name, cookie_val))

    # read cookie
    def read_secure_cookie(self, name):
        cookie_val = self.request.cookies.get(name)
        return cookie_val and check_secure_val(cookie_val)

    def login(self, user):
        self.set_secure_cookie('user_id', str(user.key().id()))

    def logout(self):
        self.response.headers.add_header('Set-Cookie', 'user_id=; Path=/')

    def initialize(self, *a, **kw):
        webapp2.RequestHandler.initialize(self, *a, **kw)
        uid = self.read_secure_cookie('user_id')
        self.user = uid and User.by_id(int(uid))


def blog_key(name = 'default'):
    return db.key.from_path('blogs',name)

class Post(db.Model):
    subject = db.StringProperty(required = True)
    #greater than 500 words.
    content = db.TextProperty(required = True)
    created = db.DateTimeProperty(auto_now_add = True)
    last_modified = db.DateTimeProperty(auto_now = True)

    def render(self):
        self._render_text = self.content.replace('\n', '<br>')
        return render_str("post.html", p = self)



#User database table
class User(db.Model):
    username = db.StringProperty(required = True)
    password_hash = db.StringProperty(required = True)
    email = db.StringProperty()

    @classmethod
    def by_id(cls, uid):
        return User.get_by_id(uid)

    @classmethod
    def by_name(cls, name):
        u = User.all().filter('name =', name).get()
        return u

    @classmethod
    def register(cls, username, password, email = None):
        password_hash = make_pw_hash(username, password)
        return User(username = username,
                    password_hash = password_hash,
                    email = email)

    @classmethod
    def login(cls, name, pw):
        u = cls.by_name(name)
        if u and valid_pw(name, pw, u.pw_hash):
            return u
    #def render(self):


def top_posts(update = False):
    key = 'top'
    updated_time_key = "updated"
    posts = memcache.get(key)
    time1 = memcache.get(updated_time_key)
    if posts is None or update:
        logging.error("DB Query")
        posts = db.GqlQuery("SELECT * FROM Post ORDER BY created DESC;")
        time_updated = time.time()
        memcache.set(updated_time_key,time_updated)
        memcache.set(key,posts)
    return posts,time1

class MainPageHandler(Handler):
    def render_front(self):
        #posts = db.GqlQuery("SELECT * FROM Post ORDER BY created DESC;")
        params = {}
        postTimeTuple = top_posts()
        params['posts'] = postTimeTuple[0]
        params['time'] = int(time.time() - postTimeTuple[1])
        #Gql substitute
        #posts = greetings = Post.all().order('-created')
        #self.render("blogMainPage.html",posts = posts)
        self.render("blogMainPage.html",**params)

    def get(self):
        self.render_front();

    # def onMyClick(self,p):
    #     if p:
    #         idValue = p.key().id()
    #         self.redirect("/blog/%s" % idValue)

# class redirecting to  the permanant page for a blog entry
class PermanentLinkHandler(Handler):
    def render_front(self,post):
        self.render("permalink.html",post = post)

    def get(self,post_id):
        key = db.Key.from_path('Post',int(post_id))
        post = db.get(key)

        if not post:
            self.error(404)
            return

        self.render_front(post)
        print self

# class for a new post entry page
class NewPostHandler(Handler):
    def render_front(self,subject="",content="",error=""):
        self.render("new_entry.html",subject = subject,content = content,error = error)

    def get(self):
        if self.user:
            self.render_front()
        else:
            self.redirect("/login")


    def post(self):
        if not self.user:
            self.redirect('/blog')

        subject = self.request.get("subject")
        content = self.request.get("content")

        if subject and content:

            a = Post(subject = subject, content = content)
            #store in the database
            a.put()
            idValue = a.key().id()

            #update cache
            top_posts(True)

            #print "key is --> "+ str(idValue)
            self.redirect("/blog/%s" % idValue)

        else:
            error = "we need both title and some content"
            self.render_front(subject,content,error)


##### HW1 sign up
# class Rot13(BlogHandler):
#     def get(self):
#         self.render('rot13-form.html')
#
#     def post(self):
#         rot13 = ''
#         text = self.request.get('text')
#         if text:
#             rot13 = text.encode('rot13')
#
#         self.render('rot13-form.html', text = rot13)


class LoginHandler(Handler):
    def get(self):
        self.render("login-form.html")

    def post(self):
        have_error = False
        username = self.request.get('username')
        password = self.request.get('password')

        params = {}

        if not valid_username(username):
            params['general_error'] = "That's not a valid username."
            have_error = True

        if not valid_password(password):
            params['general_error'] = "That wasn't a valid password."
            have_error = True

        if have_error:
            self.render('login-form.html', **params)
        else:
            # user = db.GqlQuery("SELECT * FROM User WHERE username = :name",name =  username)
            # #print " uuser get function is --> " +  str(user.get())
            # if user.get() and valid_pw(username,password,user.get().password_hash):
            #     self.login(user.get())
            #     self.redirect('/welcome')
            u = User.login(username, password)
            if u:
                self.login(u)
                self.redirect('/blog')
            else:
                params['general_error'] = 'That was not a valid username or password'
                self.render('login-form.html', **params)


class Welcome(Handler):
    def get(self):
        COOKIE_NAME = 'user_id'
        user_cookie_str = self.read_secure_cookie(COOKIE_NAME);

        if user_cookie_str:
             key = db.Key.from_path('User',int(user_cookie_str))
             user = db.get(key)
             username = user.username
             self.render('welcome.html', username = username)
        else:
            self.redirect('/signup')


class LogoutHandler(Handler):
    def get(self):
        self.logout()
        self.redirect('signup')


class Signup(Handler):

    def get(self):
        self.render("signup-form.html")

    def post(self):
        have_error = False
        self.username = self.request.get('username')
        self.password = self.request.get('password')
        self.verify = self.request.get('verify')
        self.email = self.request.get('email')

        self.params = dict(username = self.username,
                      email = self.email)

        if not valid_username(self.username):
            self.params['error_username'] = "That's not a valid username."
            have_error = True

        if not valid_password(self.password):
            self.params['error_password'] = "That wasn't a valid password."
            have_error = True

        elif self.password != self.verify:
            self.params['error_verify'] = "Your passwords didn't match."
            have_error = True

        if not valid_email(self.email):
            self.params['error_email'] = "That's not a valid email."
            have_error = True

        if have_error:
            self.render('signup-form.html', **self.params)
        else:
            self.done()


    def done(self, *a, **kw):
        raise NotImplementedError

class Unit2Signup(Signup):
    def done(self):
        self.redirect('/unit2/welcome?username=' + self.username)

class RegisterHandler(Signup):
    def done(self):
        #make sure the user doesn't already exist
        #u = User.by_name(self.username)
        u = db.GqlQuery("SELECT * FROM User WHERE username = :name",name = self.username)
        if u.get():
            msg = 'That user already exists.'
            self.params['error_username'] = msg
            self.render('signup-form.html',**self.params)
        else:
            u = User.register(self.username, self.password, self.email)
            u.put()
            self.login(u)
            self.redirect('/blog')

        # # My implemmentation set cookie insead
        # password_hash = make_pw_hash(username,password)
        # a = User(username = username,password_hash = password_hash)
        # a.put()
        # entity_id = a.key().id()
        #
        # COOKIE_NAME = 'user_cookie'
        #
        # #visit_cookie_str = self.request.cookies.get(COOKIE_NAME)
        # #set the cookie
        # new_cookie_val = make_secure_val(str(entity_id))
        # self.response.headers.add_header('Set-Cookie',COOKIE_NAME+'=%s' % new_cookie_val)
        #
        # self.redirect('/welcome')


class MainPage(Handler):
  def get(self):
      self.write('Hello, Harish!')


app = webapp2.WSGIApplication([('/', MainPage),
                               ('/unit2/signup', Unit2Signup),
                               ('/signup', RegisterHandler),
                               ('/welcome', Welcome),
                               ('/blog/?',MainPageHandler),
                               ('/blog/newpost',NewPostHandler),
                               (r'/blog/([0-9]+)',PermanentLinkHandler),
                               ('/login',LoginHandler),
                               ('/logout',LogoutHandler)], debug=True)
