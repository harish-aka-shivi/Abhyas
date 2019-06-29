#include<iostream>
using namespace std;


void printArray(int arr[], int n) {
	int l = 0;

	while(l < n) {
			cout << arr[l] << " ";
			l++;
	}
}

// arr - input array
// n - size of array
void InsertionSort(int arr[], int n){
	for(int i = 1; i < n; i++) {
	    int temp = arr[i];
	    int j;
	    for(j = i-1; j >= 0; j--) {
	        int k;
	        if(arr[j]>temp) {
	            arr[j+1] = arr[j];
							arr[j] = 0;
	            //cout << " arr[j+1] " << arr[j]<< " "<< arr[j+1] << endl;
	        }else {
	            break;
	        }
	    }
			j = j+1;
	    arr[j] = temp;
		}

		//printArray(arr,n);

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
  InsertionSort(arr,n);
}
