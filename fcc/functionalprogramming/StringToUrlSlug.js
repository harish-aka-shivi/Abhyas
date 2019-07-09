var globalTitle = "Winter Is Coming";


function urlSlug(title) {
    return title.split(" ").filter(function(item) {
        return item != ''
    }).join("-").toLowerCase();
  
}


var winterComing = urlSlug(globalTitle); // Should be "winter-is-coming"
