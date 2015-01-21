var sortTarget = function () {
  var array = new Array();
  for (var i = 0; i < 1000; i++) {
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
          // swap処理。
          // ただ前後の値を入れ替える単純な処理を、
          // ひたすら全部揃うまでやるだけ。
          j = sort[i];
          sort[i] = sort[i+1];
          sort[i+1] = j;
        }
      };
    }while(flag);
    return sort;
  },
  swap: function(items, lower, upper) {
    var temp = items[lower];
    items[lower] = items[upper];
    items[upper] = temp;
  },
  // クイックソートの基準値を返す関数
  partition: function (data, bottom, top) {
    var pivot = data[bottom];
    // 両端の値を設定。
    var lower = bottom;
    var upper = top;
    while (lower <= upper) {
      while (data[lower] < pivot) {
        lower++;
      }
      while (data[upper] > pivot) {
        upper--;
      }
      if (lower <= upper) {
        this.swap(data, lower, upper);
        lower++;
        upper--;
      }
    }
    return lower;
  },
  quick: function (data, bottom, top) {
    var self = this;
    if (bottom >= top) { return; }
    // 基準値の周りで並び替えが終わったらそのサイクルは終了。
    // ここからがいわゆるpartition（基準点）を作る処理
    // 便宜上左端の値を基準値にしている。
    var index = self.partition(data, bottom, top);
    self.quick(data, bottom, index-1);
    self.quick(data, index, top);
    return data;
  }
}



var sort = new Sort();
var data = sortTarget();
console.log(data);
console.log(sort.quick(data,0, data.length-1));
