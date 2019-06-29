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
  }


// this method sorts in O(n) time
  void segregate0and1(int arr[]) { 
        int type0 = 0; 
        int type1 = arr.length - 1; 
          
        while (type0 < type1) { 
            if (arr[type0] == 1) { 
                // swap 
                arr[type1] = arr[type1]+ arr[type0]; 
                arr[type0] = arr[type1]-arr[type0]; 
                arr[type1] = arr[type1]-arr[type0]; 
                type1--; 
            } else { 
                type0++; 
            } 
        } 
  
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






// there is one another way
// This one here sort an array of 1 0 and 2. 
// static void sort012(int a[], int arr_size)
//     {
//         int lo = 0;
//         int hi = arr_size - 1;
//         int mid = 0,temp=0;
//         while (mid <= hi)
//         {
//             switch (a[mid])
//             {
//             case 0:
//             {
//                 temp   =  a[lo];
//                 a[lo]  = a[mid];
//                 a[mid] = temp;
//                 lo++;
//                 mid++;
//                 break;
//             }
//             case 1:
//                 mid++;
//                 break;
//             case 2:
//             {
//                 temp = a[mid];
//                 a[mid] = a[hi];
//                 a[hi] = temp;
//                 hi--;
//                 break;
//             }
//             }
//         }
//     }
