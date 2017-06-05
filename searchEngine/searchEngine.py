#Finishing the page ranking algorithm.
# struck of graph {url:[outgoing pages] }
def compute_ranks(graph):
    d = 0.8 # damping factor
    numloops = 10

    ranks = {}
    npages = len(graph)

    #set initial rank to all the pages
    for page in graph:
        ranks[page] = 1.0 / npages

    for i in range(0, numloops):
        newranks = {}
        for page in graph:
            newrank = (1 - d) / npages
            for node in graph:
                if page in graph[node]:
                    newrank = newrank + d*(ranks[node]/len(graph[node]))
            newranks[page] = newrank
        ranks = newranks
    return ranks





#testing for the time
# makes big index and
def make_big_index(size):
    index = []
    letters = ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a']
    while len(index) < size:
        #TODO:make make_string method
        word = make_string(letters)
        add_to_index(index, word, 'fake')
        for i in range(len(letters) - 1, 0, -1):
            if letters[i] < 'z':
                  letters[i] = chr(ord(letters[i]) + 1)
                  break
            else:
                   letters[i] = 'a'
    return index


def record_user_click(index, keyword, url):
    urls = lookup(index, keyword)
    if urls:
        for entry in urls:
            if entry[0] == url:
                entry[1] = entry[1]+1

# check for url  in indexed list like above function
# def record_user_click(index,keyword,url):
#     for entry in index:
#         if entry[0] == keyword:
#             for url_pair in entry[1]:
#                 if url_pair[0] == url:
#                     url_pair[1] += 1;
#                     return;


#OLD
# #Function to do indexing of pages
# Data struct is like [keyword,[url]]
# def add_to_index(index, keyword, url):
#     for entry in index:
#         if entry[0] == keyword:
#             entry[1].append(url)
#             return
#     index.append([keyword, [url]])

#
# #change of datastructure for storing the url and associated clicks also
# # does indexing , stores variable in a list
# def add_to_index(index, keyword, url):
#     # format of index: [[keyword, [[url, count], [url, count],..]],...]
#     for entry in index:
#         if entry[0] == keyword:
#             for urls in entry[1]:
#                 if urls[0] == url:
#                     return
#             entry[1].append([url,0])
#             return
#     # not found, add new keyword to index
#     index.append([keyword, [[url,0]]])
#


#change of datastructure for storing the url and associated clicks also
# does indexing , stores variable in a list
def add_to_index(index, keyword, url):
    # format of index: [[keyword, [[url, count], [url, count],..]],...]
    if keyword in index:
        index[keyword].append(url)
    else:
        index[keyword] = [url]

#  does look of a key word and return its associated url and number of clicks
def lookup(index, keyword):
    if keyword in index:
        return index[keyword]
    return None
    # for entry in index:
    #     if entry[0] == keyword:
    #         return entry[1]
    # return []

def add_page_to_index(index, url, content):
    words = content.split()
    for word in words:
        add_to_index(index, word, url)


# def get_page(url):
#     try:
#         if url == "http://www.udacity.com/cs101x/index.html":
#             return ('<html> <body> This is a test page for learning to crawl! '
#             '<p> It is a good idea to '
#             '<a href="http://www.udacity.com/cs101x/crawling.html">learn to '
#             'crawl</a> before you try to  '
#             '<a href="http://www.udacity.com/cs101x/walking.html">walk</a> '
#             'or  <a href="http://www.udacity.com/cs101x/flying.html">fly</a>. '
#             '</p> </body> </html> ')
#         elif url == "http://www.udacity.com/cs101x/crawling.html":
#             return ('<html> <body> I have not learned to crawl yet, but I '
#             'am quite good at '
#             '<a href="http://www.udacity.com/cs101x/kicking.html">kicking</a>.'
#             '</body> </html>')
#         elif url == "http://www.udacity.com/cs101x/walking.html":
#             return ('<html> <body> I cant get enough '
#             '<a href="http://www.udacity.com/cs101x/index.html">crawling</a>! '
#             '</body> </html>')
#         elif url == "http://www.udacity.com/cs101x/flying.html":
#             return ('<html> <body> The magic words are Squeamish Ossifrage! '
#             '</body> </html>')
#     except:
#         return ""
#     return ""

def get_page(url):
    from six.moves import urllib
    resp = urllib.request.urlopen('http://www.python.org')
    c = resp.read()
    print "hitting url  --> ", url
    # if url == '/about/legal/':
    #     print c
    #print c
    return c


def get_next_target(page):
    start_link = page.find('<a href=')
    if start_link == -1:
        return None, 0
    start_quote = page.find('"', start_link)
    end_quote = page.find('"', start_quote + 1)
    url = page[start_quote + 1:end_quote]
    return url, end_quote

def union(p,q):
    for e in q:
        if e not in p:
            p.append(e)

def get_all_links(page):
    links = []
    while True:
        url,endpos = get_next_target(page)
        if url:
            links.append(url)
            page = page[endpos:]
        else:
            break
    return links

def crawl_web(seed, max_pages):
    tocrawl = [seed]
    crawled = []
    count = max_pages
    index = {}
    graph = {}
    while tocrawl:
        page = tocrawl.pop()
        if page not in crawled and len(crawled) < max_pages:
            content = get_page(page)
            add_page_to_index(index,page,content)
            outlinks = get_all_links(content)
            graph[page] = outlinks
            union(tocrawl, outlinks)
            crawled.append(page)
        count = count - 1
    return index,graph


# this is I think is breath first search
# as dfs is not very effective in crawling


# code with keeping depth in mind
#def crawl_web(seed, max_depth):
#    tocrawl = [seed]
#    crawled = []
#    depth = 0
#    next_depth = []
#
#    while tocrawl and depth < max_depth:
#        page = tocrawl.pop()
#        if page not in crawled:
#            union(next_depth, get_all_links(get_page(page)))
#            crawled.append(page)
#        means if tocrawl is empty
#        if not tocrawl:
		#tocrawl,next_depth = next_depth,[]
		# depth = depth+1
#
#    return crawled


#Demo
#index, graph = crawl_web('http://udacity.com/cs101x/urank/index.html',10)
index, graph = crawl_web('https://en.wikipedia.org/wiki/Directed_graph',10)
print len(index)
print len(graph)
print compute_ranks(graph)
