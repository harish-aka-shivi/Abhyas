//An immediately invoked function expression (IIFE) is often used to 
//group related functionality into a single object or module.

let singMixin = function(obj) {
  obj.sing = function() {
    console.log("Singing to an awesome tune");
  };
};

let funModule = (function() {
  return{
    isCuteMixin : function(obj) {
      obj.isCute = function() {
      return true;
      };
    },
    singMixin:function(obj) {
      obj.sing = function() {
      console.log("Singing to an awesome tune");
      };
    }
  }
})();
