// var arr = [4, 5, 3, 7, 2];

// function quickSort(arr){
//     var left = [];
//     var right = [];
//     var pivot = arr[0];


//     for(var i = 1 ; i < arr.length ;i++){
//       arr[i] < pivot ? left.push(arr[i]) : right.push(arr[i]);
//     }

//     return [...left, pivot, ...right];
// }

// console.log("Sorting started");
// // var new_arr = quickSort(arr);
// // console.log(new_arr);
// var a = [-20, -3916237, -357920 ,-3620601, 7374819, -7330761, 30, 6246457, -6461594 ]
// console.log(a.sort());


// var arr = [1,2,3,4,5];

// function sum(arr, n){
//   var sum = 0;
//   arr.map(ar => { sum += ar});
//   return sum;
// }

// console.log(sum(arr, arr.length));




// var a = 20;
// var b = 10;

// function sum_of_numbers(a, b) {
//   var c = a + b;
//   return c;
// }

// console.log(sum_of_numbers(a,b));

// var arr = [2, 9, 7, 5, 1, 3, 0, 4, 6, 8];

// function maxArray(arr) {
//   var max = arr[0];
//   for (var i = 1; i < arr.length; i++) {
//     if(max < arr[i]){
//       max = arr[i];
//     }
//   }
//   return max;
// }

// console.log(maxArray(arr));



// var num = 15;

// function sumOfAllNumbersUptoN(num){
//   var sum = 0;
//   for(var i = 1; i <= num; i++){
//     sum += i;
//   }
//   return sum;
// }

// console.log(sumOfAllNumbersUptoN(num));


// var arr = []
// for(var i  = 0 ; i < 100 ; i++){
//   arr.push(i);
// }
// //shuffling of array
// arr = arr.sort(() => Math.random() - 0.5)

// function maxArray(arr) {
//   var max = arr[0];
//   for (var i = 1; i < arr.length; i++) {
//     if(max < arr[i]){
//       max = arr[i];
//     }
//   }
//   return max;
// }

// console.log(maxArray(arr));



/**
 * Coding Max heap on my own
 * Bismillah hir rehmanir rahim
 */

class MaxHeap {

  constructor() {
    this.capacity = 10;
    this.size = 0;

    this.items = new Array(this.capacity).fill(0);
  }

  add = (item) => {
    this.ensureCapacity();
    this.items[this.size++] = item;
    this.heapifyUp();
  }

  pullMax = () => {
    if (this.size >= 0) {
      let ans = this.items[0];
      this.items[0] = this.items[--this.size];
      this.heapifyDown();
      return ans;
    }
    return -1;
  }

  peak = () => {
    return this.items[0];
  }

  heapifyDown = () => {
    var index = 0;
    while (this.hasLeftChild(index)) {
      var largerIndex = this.getLeftChildIndex(index);
      if (this.hasRightchild(index) && this.getLeftchild(index) < this.getRightChild(index)) {
        largerIndex = this.getRightChildIndex(index);
      }
      if (this.items[index] > this.items[largerIndex]) {
        break;
      }
      else {
        this.swap(index, largerIndex);
        index = largerIndex;
      }
    }
  }

  heapifyUp = () => {
    var index = this.size - 1;
    while (this.hasParent(index) && this.getParent(index) < this.items[index]) {
      this.swap(this.getParentIndex(index), index);
      index = this.getParentIndex(index);
    }
  }

  swap = (index_one, index_two) => {
    var temp = this.items[index_one];
    this.items[index_one] = this.items[index_two];
    this.items[index_two] = temp;
  }

  ensureCapacity = () => {
    if (this.size === this.capacity) {
      my_items = new Array(this.capacity * 2).fill(0);
      for (var i = 0; i < this.capacity; i++) {
        my_items[i] = items[i];
      }
      this.capacity *= this.capacity;
    }
  }

  getParentIndex = (index) => {
    return Math.floor((index - 1) / 2);
  }
  getLeftChildIndex = (index) => {
    return (index * 2 + 1);
  }
  getRightChildIndex = (index) => {
    return (index * 2 + 2);
  }

  hasParent = (index) => {
    return this.getParentIndex(index) >= 0;
  }
  hasLeftChild = (index) => {
    return this.getLeftChildIndex(index) < this.size;
  }
  hasRightchild = (index) => {
    return this.getRightChildIndex(index) < this.size;
  }

  getRightChild = (index) => {
    return this.items[this.getRightChildIndex(index)];
  }
  getLeftchild = (index) => {
    return this.items[this.getLeftChildIndex(index)];
  }
  getParent = (index) => {
    return this.items[this.getParentIndex(index)];
  }

}

var h = new MaxHeap();
h.add(5);
h.add(2);
h.add(10);
h.add(200);
console.log(h.pullMax());
console.log(h.pullMax());
console.log(h.pullMax());
console.log(h.pullMax());
console.log(h.pullMax());
console.log(h.size);
console.log(h.items);



