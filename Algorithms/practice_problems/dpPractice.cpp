#include <iostream>
using namespace std;
int fibUsingDp(int n, int* arr) {
   if( n == 0 || n == 1) {
       return 1;
   }
   if(arr[n] > 0) {
     return arr[n];
   }
   int output = fibUsingDp(n-1,arr) + fibUsingDp(n-2,arr);
   arr[n] = output;
   return output;
}

int main() {
   int n;
   cin >> n;
   //  dynamic alloacation
   int* arr = new int[n+1];
   for(int i=0; i <= n; i++) {
     arr[i] = 0;
  }
  std::cout << fibUsingDp(n,arr) << std::endl;
}
