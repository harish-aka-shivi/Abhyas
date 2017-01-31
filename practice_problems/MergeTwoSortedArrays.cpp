#include<iostream>
using namespace std;


int mergeTwoArrays(int a[],int b[],int sizeA,int sizeB) {
    cout << "size A + size B" << sizeA+sizeB << endl;
    int ans[20];
    int i= 0;
    int j = 0;
    int k = 0;
    while (i <   sizeA && j <sizeB) {
      if(a[i] < b[j]) {
        ans[k] = a[i];
        i++;
        k++;
      } else {
        ans[k] = b[j];
        j++;
        k++;
      }
    }
    while (i < sizeA) {
      ans[k] = a[i];
      i++;
      k++;
    }
    while (j < sizeB) {
      ans[k] = b[j];
      j++;
      k++;
    }
    int c = 0;
    cout << "array is "<<endl;
    while(c< sizeA+sizeB) {
      cout << ans[c] << " ";
      c++;
    }
  }

  int main() {
    int a,b;
    cout << "length of first array";
    cin >> a;
    int firstArray[20];
    cout << "length of second array";
    cin >> b;
    int secondArray[20];
    int i = 0;
    cout << "enter element of first array";
    while(i < a) {
      //cout << "a,n is "<< a << ", " << n << " ";
      cin >> firstArray[i];
      i++;
    }
    int j = 0;
    cout << "enter element of second array";
    while(j < b) {
      cin >> secondArray[j];
      j++;
    }
    mergeTwoArrays(firstArray,secondArray,a,b);
    return 0;
  }
