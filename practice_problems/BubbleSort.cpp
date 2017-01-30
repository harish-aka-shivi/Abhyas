#include<iostream>
using namespace std;

int main() {
    int i,j;
    int[] demoArray = [4,2,5,6];
    int size;

    while(i  < size-1) {
      j = i+1;
      if(demoArray[i] >= demoArray[j]) {
          int a = demoArray[i];
          demoArray[i] = demoArray[j];
          demoArray[j] = a;
      }
      i++;
    }



}
