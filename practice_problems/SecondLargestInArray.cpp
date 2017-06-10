#include<iostream>
using namespace std;

// arr - input array
// n - size of array
int FindSecondLargest(int arr[], int n){
// Write your code here
  if(n <= 1) {
      return 12222;
  }
  int max = -32765;
  int maxIndex;
  int secondMax;
  for(int i =0; i <n ; i++) {
      if(arr[i] > max) {
          max = arr[i];
          maxIndex = i;
      }
  }

  for(int i = 0; i < n ; i++) {
      if(arr[i] > secondMax && arr[i] <max) {
          secondMax = arr[i];
      }
  }

  return secondMax;
}
