
// join is used to join array into a string

function sentensify(str) {
  let a = str.split(/[^A-Za-z0-9]/);
  return a.join(" ")
}
sentensify("May-the-force-be-with-you");
