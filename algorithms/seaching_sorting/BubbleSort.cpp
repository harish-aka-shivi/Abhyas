#include<iostream>
using namespace std;

int main() {
    int i,j;
    int demoArray[100];
    int size;
    std::cout << "Enter the size of array" << std::endl;
    cin >> size;

    std::cout << "Enter the array" << std::endl;
    int k = 0;
    while(k < size) {
      cin >> demoArray[k];
      k++;
    }

    // it can be run size-tiime according to me.
    for (int l = 0 ; l < size ; l++) {
    int i = 0;
    int j = 0;
    while(i  < size-1) {
      j = i+1;
      if(demoArray[i] > demoArray[j]) {
          int a = demoArray[i];
          demoArray[i] = demoArray[j];
          demoArray[j] = a;
      }
      i++;
    }
    int m = 0;

    std::cout << "Array after every iteration" << endl;
    while(m < size) {

      std::cout << demoArray[m] <<  " ";
      m++;
    }
    std::cout << "" << std::endl;
  }

  int m = 0;
  while(m < size) {
    std::cout << demoArray[m] <<  " ";
    m++;
  }



}
