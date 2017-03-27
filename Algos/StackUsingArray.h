class StackUsingArray {
  // by default private
  int * data;
  int nextIndex;
  int capacity;

public:
  StackUsingArray {
    capacity = 10;
    data = new int[capacity];
    nextIndex = 0;
  }


  int size() {
      return nextIndex;
    }

  bool isEmpty() {
     return size() == 0;
  }

  void push(int element) {
    if(nextIndex == capacity) {
      // we wil expand in the future
       return;
     }
     data[nextIndex] = element;
     nextIndex++;
  }

  int pop() {
    if(size == 0) {
      //throw some error
    }

  }



}
