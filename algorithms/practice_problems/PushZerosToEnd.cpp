#include<iostream>
using namespace std;



//Sample input
//7
//2 0 4 1 3 0 28

//ample output
//2 4 1 3 28 0 0


void printArray(int arr[], int n) {
	int l = 0;

	while(l < n) {
			cout << arr[l] << " ";
			l++;
	}
}


// arr - input array
// n - size of array
void PushZeroesEnd(int arr[], int n){
	// Write your code here
	int i = 0; int j = n-1;

	while(i <= j) {
	   if(arr[i] == 0)  {
	        //arr[j] = 0;
	        int k = i;
	        while(k < n) {
	            arr[k] = arr[k+1];
	            k++;
	        }
	        arr[n-1] = 0;
	        j--;
	    }
	    i++;
	}

}

int main() {
  int n;
  int arr[1000];
  cin >> n;
  int i = 0;
  while(i < n) {
    cin >> arr[i];
    i++;
  }
  PushZeroesEnd(arr,n);
}
