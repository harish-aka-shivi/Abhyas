#include<iostream>
using namespace std;
#define PI 3.14
// PI is pre compiled use it anyehre

//this is also replaces at compile time
// increase perf and readibilty
inline int min(int a, int b) {
  return (a>b)? b:a;
}


void swap(char* & x, char* & y) {
  char*t = x;
  x = y;
  y = t;
}

int main() {
  int i = 10;
  int & j = i;
  // have to given reference
  // cannot do int &j;
  // have to be initialized

  j = 12;
  //this means i = 12;
  // this is how we can pass by reference.
  int k = 10;
  int *p = &k;
  std::cout << p << "  " << *p << std::endl;

}

// do  not pass local variable as pointer or referecce.

///Address typecasting


// Dynamic Memory location
 //Two Memory spaces stack and heap.
 // 2 d memory allocation

// constant variable
// have to be initialized like c++;
int demo() {
  int const x = 10;
  int i = 10;
  int const &j = 1;

  i++;// possibe
  j++; // not possible
  int const z = 10;
  int & a = z;// not possible : error cannot drop const quallifier.
// memory is not constant way to reach a number is constant.
}
int pointerConst() {
  int i3 = 10;
  int * const p = &i3; // p is constant pointer to integer
  (*p)++ // possible
  p = &i4; // not possible

  int i4  = 12;
  int const * p2; // p2 is pointer to constat integer: beware its the path that is constant
  p2 = &i4; // possible
  i4 = 13 //possible
  (*p2)++ // not possible as the path is constant.

  int const * const p5 = &i4;
}

// use case constant function
void temp(int const *x) {
  *x = 122;
}

int sum(int *a, int size,int startIndex = 0) {
  inf (startIndex == 0) {
      return 0;
  }

  return a[startIndex] + sum(a,size);

}
