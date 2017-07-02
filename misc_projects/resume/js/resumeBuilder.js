
// bio contains name, role, welcomeMessage, and biopic strings, contacts object
//and skills array of skill strings. The contacts object should contain a mobile
//number, email address, github username, twitter handle and location.

//defining object
var bio = {
  "name":"Harish Rana",
  "role":"Sofware Engineer",
  "contacts":{
    "mobile":"8826374821",
    "email": "r.shivi@yahoo.com",
    "github":"harish-aka-shivi",
    "location":"Gurgaon",
    "twitter":"https://twitter.com/shivi_rana9"
  },
  "pictureURL":"https://media.licdn.com/mpr/mpr/shrink_300_300/p/8/005/0ae/245/23a9b19.jpg",
  "welcomeMessage":"kung fu programmer",
  "skills":["Progamming","Leadership","Keen Learner"]

};


bio.display = function () {

  if(bio.skills.length  > 0) {
    formattedName = HTMLheaderName.replace("%data%",bio.name);
    formattedRole = HTMLheaderRole.replace("%data%",bio.role);
    $("#header").prepend(formattedName + formattedRole);
    var fromattedPic = HTMLbioPic.replace("%data%",bio.pictureURL);
    $("#header").append(fromattedPic);
    $("#header").append(HTMLskillsStart);
    var formattedSkills = HTMLskills.replace("%data%",bio.skills[0]) +
     HTMLskills.replace("%data%",bio.skills[1]) + HTMLskills.replace("%data%",bio.skills[2]);
    $("#skills").append(formattedSkills);

  }
  var formattedContactMob = HTMLmobile.replace("%data%",bio.contacts.mobile);
  var formattedContactEmail = HTMLemail.replace("%data%",bio.contacts.email);
  var formattedContactTwitter = HTMLtwitter.replace("%data%",bio.contacts.twitter);
  var formattedContactGithub = HTMLgithub.replace("%data%",bio.contacts.mobile);
  $("#topContacts").append(formattedContactMob);
  $("#topContacts").append(formattedContactEmail);
  $("#topContacts").append(formattedContactTwitter);
  $("#topContacts").append(formattedContactGithub);
};

bio.display();



//dot notation
var work1 = {};
work1.jobPosition = "Android Developer";
work1.employer = "Staqu";
work1.experience = "1 years";
work1.date = "July,2016 - now";
work1.description = "Implemented features like custom scaling, re-positioning and" +
"caching of images and stickers.\n" +"Integrated Google play services and Firebase Messaging service.\n" +
"Uses Libraries like UIL,ButterKnife,ucrop for image manipulation.";
work1.location = "Gurgaon";

var work2 = {};
work2.jobPosition = "Software Developer";
work2.employer = "Code For India";
work2.experience = "6 months";
work2.date = "Jan,2016 - June,2016";
work2.description  = "Collabrated with fellow developers to make educational"+
"application to help kids in africa to learn language and math skils.\n" +
"Help develop the content and implement the technical aspect of it.\n"+
"Designed and programmed bots to ask math problems and translator text in 32 languages using bing apis.\n"+
"Helped Design the app to be multi-linguistic"
work2.location = "Banglore";


//work contains an array of jobs. Each object in the jobs array should contain
// an employer, title, location, dates worked and description strings.
var work  = {
  "jobs":[work2,work1]
}


//education contains an array of schools. Each object in the schools array contains
// name, location, degree dates and url strings, and amajors array of major strings.
//education also contains an onlineCourses array. Each object in the onlineCourses
// array should contain a title, school, dates and url strings.

//bracket notation
var education = {
  "schools":[],
  "onlineCourses" : []
};

var school1 = {
  "name":"D.A.V. public school",
  "location":"Panipat",
  "degree":"10+2",
  "majors":"Science(PCM)",
  "dates": "till 2010"
};
var school2 = {
  "name":"Manav Rachna College of Engineering",
  "location":"Faridabad",
  "degree":"Bachelors of Technology",
  "majors":"Electronics and Communication Engineering",
  "dates": "2011-2015"
};

education["schools"].push(school1);
education["schools"].push(school2);

var onlineCourse1 = {
  "title":"An introduction to interactive programming using python(I and II)",
  "school":"Coursera",
  "data":"2015",
  "url":"https://www.coursera.org/learn/interactive-python-1"
};

var onlineCourse2 = {
  "title":"Intro to computer Science",
  "school":"Udacity",
  "data":"2016",
  "url":"https://www.udacity.com/course/intro-to-computer-science--cs101"
};

var onlineCourse3 = {
  "title":"Android Nanodegree",
  "school":"Udacity",
  "data":"2016",
  "url":"https://in.udacity.com/course/android-developer-nanodegree-by-google--nd801/"
};

var onlineCourse4 = {
  "title":"Intro to Relational databases",
  "school":"Udacity",
  "data":"2017",
  "url":"https://www.udacity.com/course/intro-to-relational-databases--ud197"
};

education.onlineCourses.push(onlineCourse1);
education.onlineCourses.push(onlineCourse2);
education.onlineCourses.push(onlineCourse3);
education.onlineCourses.push(onlineCourse4);


education.display = function() {
  var numSchools = education.schools.length;
  //console.log("number of schools - >" + numSchools );
  for(var i = 0; i < numSchools;i++) {
    $("#education").append(HTMLschoolStart);

    var formattedSchoolName = HTMLschoolName.replace("%data%",education.schools[i].name);
    var formattedSchoolDegree= HTMLschoolDegree.replace("%data%",education.schools[i].degree);

    var formattedSchoolLoc = HTMLschoolLocation.replace("%data%",education.schools[i].location);
    var formattedSchoolMajors = HTMLschoolMajor.replace("%data%",education.schools[i].majors);
    var formattedSchoolDates = HTMLschoolDates.replace("%data%",education.schools[i].dates);


    $(".education-entry:last").append(formattedSchoolName + formattedSchoolDegree);
    $(".education-entry:last").append(formattedSchoolDates);

    $(".education-entry:last").append(formattedSchoolLoc);
    //$(".education-entry:last").append(formattedSchoolDegree);
    $(".education-entry:last").append(formattedSchoolMajors);

    }

    var onlineCoursesLen = education.onlineCourses.length;
    $("#education").append(HTMLonlineClasses);
    for(var i = 0; i < onlineCoursesLen; i++) {
      $("#education").append(HTMLschoolStart);

      var onlineTitle = HTMLonlineTitle.replace("%data%",education.onlineCourses[i].title);
      var onlineSchool = HTMLonlineSchool.replace("%data%",education.onlineCourses[i].school);
      var onlineDate = HTMLonlineDates.replace("%data%",education.onlineCourses[i].data);
      var onlineCourseLink = HTMLonlineURL.replace("%data%",education.onlineCourses[i].url);
      $(".education-entry:last").append(onlineTitle + onlineSchool);
      $(".education-entry:last").append(onlineDate);
      $(".education-entry:last").append(onlineCourseLink);



    }
};

education.display();
//projects contains an array of projects. Each object in the projects array
//should contain title, dates and description strings, and an images array with URL strings for project images.
var projects = {
  "project":[]
}

var project1 = {
  "title":"Vistoso",
  'dates':'Jan 2017 - Present',
  'description':'Responsible for the design, build, deployment, debug & maintenance of   '+
  'Android applications for Google play'+
  'Implemented features like custom scaling, re-positioning and caching of images and stickers'+
  'Integrated Google play services and Firebase Messaging service.'+
  'User able to order printed t-shirts,mug,posters with the option  to customize.'+
  'Photo Editor using android native graphics, bitmap manipulation, filtering etc.'+
  'Integrated user login, Cart and payment and order tracking'+
  'Uses Libraries like UIL,ButterKnife,ucrop for image manipulation.',
  'images':["https://lh3.googleusercontent.com/yIfXnyZzsyJ6hZ16t_d7kgEbZHqoJbuTpHP8Udyhoxt8UAHwgQHktJgyAoRX_rx19g=h900",
'https://lh3.googleusercontent.com/EZCdzsXbrhtVRU3XP7PvpukNVcz4FVXR6pgIhwrVDGeDB6aNDSyD6kMk_0ue2cNR5xk=h900']
};


var project2 = {
  'title':'Fashin',
  'dates':'Jan 2017 - Present',
  'description':'Understanding and working on the existing codebase to include new features.'+
                'Collabrating with associate developers using git, gitlab and MantisBT to effectively deliver the robust product within time limits.'+
                'Implemented YouTube player, google maps to provide rich user experience'+
                'Enabled Deep linking of app and implented notifications using google cloud messaging.'+
                'Integrated  features like wishlist , account settings, seaching, location based information to provide a real personal feel  to user.'+
                'Social media integration with Facebook and Twitter.',
  'images':['https://lh3.googleusercontent.com/8w9r5Rsd_-7kqixRn-yvWkUPvMJmJp9ElDZJVEWKhtzXUXFMIH-stM_By0AnPZFNoOs=h900',
         'https://lh3.googleusercontent.com/VyBjbZxxGG9wXAttbXvffi-yuD6YOT26Fc9bYgfy0oubJ53bc7IrZJPerQRshYYeUmw=h900'],
};

projects.project.push(project1);
projects.project.push(project2);
//console.log('length is ---> ' + projects.project.length);
projects.display = function() {
  projects.project.forEach(function(pro){
    $("#projects").append(HTMLprojectStart);
    var formattedTitle = HTMLprojectTitle.replace("%data%",pro.title);
    var formattedDates = HTMLprojectDates.replace("%data%",pro.dates);
    var formattedDescription = HTMLprojectDescription.replace("%data%",pro.description);
    $(".project-entry:last").append(formattedTitle);
    $(".project-entry:last").append(formattedDates);
    $(".project-entry:last").append(formattedDescription);

    for (var i = 0; i < pro.images.length; i++) {
      var formattedImage = HTMLprojectImage.replace("%data%",pro.images[i]);
      $(".project-entry:last").append(formattedImage);
    }

  });
};
projects.display();

//console.log(bio);



function displayWork() {
  var jobs = work["jobs"];
  for(job in jobs) {
    $("#workExperience").append(HTMLworkStart);
    var formatedEmployer = HTMLworkEmployer.replace("%data%",jobs[job].employer);
    var formatedJobPos = HTMLworkTitle.replace("%data%",jobs[job].jobPosition);
    var formattedConcat = formatedEmployer + formatedJobPos;

    $(".work-entry:last").append(formattedConcat);


    var formattedDates = HTMLworkDates.replace("%data%",jobs[job].date);
    var formattedDescription = HTMLworkDescription.replace("%data%",jobs[job].description);

    $(".work-entry:last").append(formattedDates);
    $(".work-entry:last").append(formattedDescription);

  }
}

displayWork();

//jquery function run every time user clicks on screen
//anonymous function
$(document).click(function(loc) {
  logClicks(loc.pageX,loc.pageY);
});

$("#main").append(internationalizeButton);


function inName(name) {
   myArr = name.split(' ');
  // console.log(myArr);
  // console.log(myArr[myArr.length - 1]);

   myArr[myArr.length - 1] = myArr[myArr.length - 1].toUpperCase();
  // console.log(myArr);
   var firstName = myArr[0];
   //couuld have used split()
   arr = Array.from(firstName);
   arr[0]=arr[0].toUpperCase();

   myArr[0] = arr.join("");
   //console.log(myArr[0]);
   return myArr.join(" ");
}

//console.log(inName("sebs thuran"));
$("#mapDiv").append(googleMap)

function getRelationship(x, y) {
    // Your code goes here!
    if(x < y) {
        return "<";
    }
    else if(x > y) {
        return ">";
    }
    else if(x === y) {
        return "=";
    }
    else{
        return "not of same type";
    }
};
