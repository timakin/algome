var searchTarget = function () {
  var array = new Array();
  for (var i = 0; i < 100; i++) {
    array[i] = i;
  };
  var shuffle = function() {return Math.random()-.5};
  return array.sort(shuffle);
}

function Search() {};
Search.prototype = {
  linearSearch: function(data, target) {
    for(item in data) {
      if(target === data[item]) {
        return item;
      }
    }
  }
}

var search = new Search();
var data = searchTarget();
console.log(data);
console.log(search.linearSearch(data, 30));