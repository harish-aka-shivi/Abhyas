// the global Array
var s = [{a:23}, {a:65}, {a:98}, {a:5}];

Array.prototype.myMap = function(callback){
  var newArray = [];
  // Add your code below this line
  console.log(this instanceof Array)
  this.forEach(function(item) {
    let a = callback(item)
    newArray.push(at);
  })
  // Add your code above this line
  return newArray;

};

var new_s = s.myMap(function(item){
  item.a = item.a * 2;
  return item;
});


console.log(JSON.stringify(s))
console.log(JSON.stringify(new_s));
