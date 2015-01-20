var sortTarget = function () {
  var array = new Array();
  for (var i = 0; i < 100; i++) {
    array.push(Math.random()*1000);
  };
  return array;
}

function Sort() {}
Sort.prototype = {
  bubble: function (sort) {
    do {
      var flag = 0;
      for (var i = 0; i < sort.length; i++) {
        if (sort[i] > sort[i+1]) {
          flag = 1
          j = sort[i];
          sort[i] = sort[i+1];
          sort[i+1] = j;
        }
      };
    }while(flag);
    return sort;
  }
}

var sort = new Sort();
console.log(sort.bubble(sortTarget()));