#include<iostream>
using namespace std;

int Search(int a[],int toBeSearched, int size) {

  int start = 0;
  int end = size - 1;

  while(start <= end) {
    int i = (start+end)/2;
    int number = a[i];
    if(a[i] == toBeSearched) {
      return i;
      break;
    } else if(a[i] > toBeSearched) {
      end = i-1;
    }else{
      start = i+1;
    }
  }
  return -1;
}

int main() {
  int n;
  cout << "enter the size:" << endl;
  cin >> n;
  int a = 0;
  int s[n];
  cout << "enter the elements" << endl;
  while(a < n) {
    //cout << "a,n is "<< a << ", " << n << " ";
    cin >> s[a];
    a = a+1;
  }

  int toBeSearched;
  cout << "enter the element to be searched" << endl;
  cin >> toBeSearched;
  int size = n;
  int i = Search(s,toBeSearched,size);
  cout << i;
  return 0;
}
