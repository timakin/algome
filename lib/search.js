var searchTarget = function () {
  var array = new Array();
  for (var i = 0; i < 10000; i++) {
    array[i] = i;
  };
  return array;
}
var searchShuffledTarget = function () {
  var array = new Array();
  for (var i = 0; i < 10000; i++) {
    array[i] = i;
  };
  var shuffle = function() {return Math.random()-.5};
  return array.sort(shuffle);
}

function Search() {};
Search.prototype = {
  linearSearch: function(data, target) {
    // 先頭から一直線に、一致する引数を探して行って、
    // もし一致するものがない場合は-1を返す。
    for(item in data) {
      if(target === data[item]) {
        return item;
      }
    }
    return -1;
  },
  // バイナリサーチ（2分探索）
  // 基準点の前後を分けて探ることで、計算量をO(logN)に抑えることができる。
  // バイナリサーチはあたいの大小を元に捜索するため、対象がソート済みの配列でなくてはならない。
  binarySearch: function(data, target) {
    var left = 0,
        right = data.length - 1,
        middle;

    while(left <= right) {
      // 基準点を毎回更新する。
      // これより大きいか小さいかで、前後のどちら半分の配列を探索するか決める
      // mid = Math.floor((left + right) / 2); // 通常の基準点の決め方
      mid = ((left+right) >> 1); // ビット演算子で右シフトすれば半分になる。これでおよそ倍速。
      // 基準点以上のどこかに探したい値がある
      // 基準点との大小関係を元に配列を分割するので、
      // そもそもソート済みじゃないと、分割する意味がないので注意。
      if (data[mid] < target) {
        left = mid + 1;
      // 基準点以下のどこかに探したい値がある
      } else if (data[mid] > target) {
        right = mid - 1;
      } else {
        // もしleftとrightが一致したら、目当てのものがみつかったので終了。 
        return mid;
      }
    }
    // 見つからなかったら-1を返す。
    return -1;
  },
  organizationSearch: function(data, target) {
    var position;
    for(i in data) {
      if (target === data[i]) {
        position = i;
        break;
      }
    }
    if (position != "undefined") {
      while(0 < position) {
        this.swap(data, position-1, position);
        position--;
      }
      return i;
    } else {
      return -1;
    }
  },
  swap: function(items, lower, upper) {
    var temp = items[lower];
    items[lower] = items[upper];
    items[upper] = temp;
  }
}

var search = new Search();
var data = searchTarget();
console.log(data);
console.log(search.binarySearch(data, 530));
var list = [1,2,3,4,5,6,7,8,9,10];
console.log(search.organizationSearch(list, 8));