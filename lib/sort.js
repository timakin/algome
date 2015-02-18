var sortTarget = function () {
  var array = new Array();
  for (var i = 0; i < 100; i++) {
    array.push(Math.random()*100);
  };
  return array;
}

function Sort() {}
Sort.prototype = {
  bubbleSort: function (sort) {
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
  quickSort: function (data, bottom, top) {
    var self = this;
    if (bottom >= top) { return; }
    // 基準値の周りで並び替えが終わったらそのサイクルは終了。
    // ここからがいわゆるpartition（基準点）を作る処理
    // 便宜上左端の値を基準値にしている。
    var index = self.partition(data, bottom, top);
    self.quickSort(data, bottom, index-1);
    self.quickSort(data, index, top);

    return data;
  },
  // MergeSort
  mergeSort: function(items){
    var self = this;

    // 受け取ったdata(配列)が、最小単位になるまで分割し続ける。
    if (items.length < 2) {
        return items;
    }

    var middle = Math.floor(items.length / 2),
        left    = items.slice(0, middle),
        right   = items.slice(middle);

    return this.merge(self.mergeSort(left), self.mergeSort(right));
  },
  merge: function(left, right){
    var result  = [],
        il      = 0,
        ir      = 0;

    while (il < left.length && ir < right.length){
        if (left[il] < right[ir]){
            result.push(left[il++]);
        } else {
            result.push(right[ir++]);
        }
    }

    // 配列で余った一番大きい値を最後にresultに入れて終了。
    return result.concat(left.slice(il)).concat(right.slice(ir));
  }
}



var sort = new Sort();
var data = sortTarget();
console.log(data);
console.log(sort.mergeSort(data, 0, data.length-1));