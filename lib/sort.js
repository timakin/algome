var sortTarget = function () {
  var array = new Array();
  for (var i = 0; i < 1000; i++) {
    array.push(Math.random()*1000);
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
  },
  // コームソート。バブルソートで少し間隔をとって比較して、徐々に近づけてくソート。
  // バブルソートと違って、すべての値の交換じゃなく、間隔を調整していくことで回数を減らすという原理。
  // 計算量はO(nLogn)。
  combSort: function(data) {
      var N = data.length;
      var gap = N;
    while((gap > 1) || flag) {
      // 収縮率（間隔調整の度合い）は1.3。
      var gap = gap*10/13;
      if (gap < 1) { gap = 1 };
      var flag = 0;
      for (var i = 0; i < N - gap; i++) {
        if (data[i] > data[i+gap]) {
          this.swap(data, i, i+gap);
          flag = 1;
        }
      }
    }
    return data;
  },
  // 選択ソート。計算量O(n^2)。
  selectionSort: function(data) {
    var min;
    for (var i = 0; i < data.length - 1; i++) {
      // 先頭を最小値とする。
      min = i;

      // 先頭から順に、それより小さい値があった場合そのうち一番小さいものと交換する。
      for (var j = i + 1; j < data.length; j++) {
        if (data[min] > data[j]) { min = j }; 
      }
      if (i != min) { this.swap(data, i, min) };
    }
    return data;
  },
  // 単純挿入ソート。最悪計算量O(n^2)。ループ回数から考えると当然。
  insertionSort: function(data) {
    // 最初から最後までソート完了になるまで繰り返す
    var tmp, i;
    for (var sorted = 0; sorted < data.length - 1; sorted++) {
      // ソート完了している領域の直後の値を取り出す。
      var insert = data[sorted+1];
      // ソート済みの中で、挿入できる場所があるかを調べる。
      for (i = 0; i <= sorted; i++) {
        if (data[i] > insert) {
          break; //ずれている部分を記憶しつつ、サーチを止める。
        }
      }
      // ずれていた箇所まで、1個ずつ要素をずらしていく。
      // 最終的にずれていた部分、１つの要素で比べようとすると止まる。
      while(i <= sorted + 1) {
        tmp = data[i];
        data[i] = insert;
        insert = tmp;
        i++;
      }
    }
    return data;
  },
  // 2分挿入ソート
  binaryInsertionSort: function(data) {
    var left, right, mid, temp;
    for (var sorted = 1; sorted < data.length; sorted++) {
      var insert = data[sorted];
      left = 0;
      right = sorted;
      while (left < right) {
        mid = Math.floor((left + right) / 2);
        if (data[mid] > insert) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      var i = left;
      while(i <= sorted) {
        temp = data[i];
        data[i] = insert;
        insert = temp;
        i++;
      }
    }
    return data;
  }
}



var sort = new Sort();
var data = sortTarget();
console.log(data);
console.log(sort.binaryInsertionSort(data));