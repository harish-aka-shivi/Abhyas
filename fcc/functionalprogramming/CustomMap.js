// the global Array
var s = [23, 65, 98, 5];

Array.prototype.myMap = function(callback){
  var newArray = [];
  // Add your code below this line
  console.log(this instanceof Array)
  this.forEach(function(item) {
    let a = callback(item)
    newArray.push(a);
  })
  // Add your code above this line
  return newArray;

};

var new_s = s.myMap(function(item){
  return item * 2;
});


console.log(new_s);
