// the global Array
var s = [23, 65, 98, 5];


//custom implementation which returns the new array when condition is met
Array.prototype.myFilter = function(callback){
  var newArray = [];

  this.forEach(function(item) {
    if(callback(item)) {
      newArray.push(item)
    }
  })

  return newArray;

};

var new_s = s.myFilter(function(item){
  return item % 2 === 1;
});
