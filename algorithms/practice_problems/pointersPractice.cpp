#include<iostream>
using namespace std;

int demoPointers() {
  float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
  float *ptr1 = &arr[0];
  float *ptr2 = ptr1 + 3;
  float a = 10.0;
//Important  when we
 ///p3 = arr;
 //float  *p3;
 //std::cout << "/arr is  /"<< arr << std::endl;
 //std::cout << "p3 before initialization is garbage value"<< *p3 << std::endl;
 //*p3 = &a;
 float *p3 = (arr+1);

 std::cout << "/arr + 1 and p3/"<< arr+1<< "   "<< p3 << std::endl;
 std::cout << "*p3 is "<<*p3 << std::endl;
 cout<<*ptr2<<" ";
 cout<< ptr2 - ptr1;
 return 0;

//ans --> 90.5 3
}

int main() {
  demoPointers();
  return 0;
}
