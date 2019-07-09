// split so that the array should not contain punctuation.
function splitify(str) {
  return str.split(/[^A-Za-z0-9]/)
  
}
console.log(splitify("Hello World,I-am code"))
splitify("Hello World,I-am code");
