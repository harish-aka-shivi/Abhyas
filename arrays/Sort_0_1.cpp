#include<iostream>
using namespace std;

// arr - input array
// n - size of array

// this is knnow as duch flag national flag problem
// some how.
void SortZeroesAndOne(int arr[], int n){
	// Write your code here
	int j = n-1;
	int i = 0;
	int k = 0;
  int count0 = 0;
  int count1 = 0;
	while(i < n) {
      if(arr[i] == 0) {
        count0 = count0 + 1;
      }else if (arr[i] == 1) {
        count1 = count1 + 1;
      }
      i++;
    }
    //cout << "count0 and count1 " << count0 << "  "<< count1 <<endl;

    k = 0;
    while (k<n) {
      if(count0 > 0) {
        arr[k] = 0;
        count0--;
      } else {
        arr[k] = 1;
      }
      k++;
    }
    int l = 0;
    while (l < n) {
      cout << arr[l] << " ";
      l++;
    }


      // if(arr[k] == 0 ) {
	    //     int temp = arr[i];
	    //     arr[i] = arr[k];
	    //     arr[k] = temp;
	    //     i++;
	    //     k++;
	    //     //printArray(arr,n);
	    // }
	    // else if(arr[k] == 1) {
	    //     int temp = arr[j];
	    //     arr[j] = arr[k];
	    //     arr[k] = temp;
	    //     j--;
	    //     k++;
	        //printArray(arr,n);
	    //}
    //}
  }

int main() {
  int n;
  int arr[100];
  cin >> n;
  int i = 0;
  while(i < n) {
    cin >> arr[i];
    i++;
  }
  SortZeroesAndOne(arr,n);
}
