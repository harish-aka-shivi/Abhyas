#include <iostream>
using namespace std;


//----------------------------------------
// Problem
// Min Steps to one
//given positive int n
//make it 1 by 3 ways
//- n-1
//- n/2 ==> n%2 == 0
//- n/3 ==> n%3 == 0
//return number of steps

// solution using normal recursion
// repetitive calculation
// TODO: implement memoization(dp)
int min_step(int n) {
  if( n == 1) {
    return 0;
  }
  int ans = 1 + min_steps(n-1);

  if(n % 2 == 0) {
    ans = min_step(ans, 1+ min_step(n/2);
  }

  if(n % 3 == 0) {
    ans = min_step(ans, 1 + min_step(n/3);
  }
}


// using dp
// bottom down approach
// avoided repetitive calculation
int minStepUsingDp(int n, int* arr) {
  if( n == 1) {
    return 0;
  }

  if(arr[n] > 0) {
    return arr[n]
  }

  int ans = 1 + minStepUsingDp(n-1,arr);

  if(n % 2 == 0) {
    ans = min(ans, 1+ minStepUsingDp(n/2,arr);
  }

  if(n % 3 == 0) {
    ans = min(ans, 1 + minStepUsingDp(n/3,arr);
  }

  arr[n] = ans;
  return ans;
}

// using bottom up approach
//  better space complexity
// no recursion
int minStep3(int n) {
  int* arr = new int[n+1]
  arr[1] = 0;
  for(int i = 2; i <= n; i++) {
    int ans = 1 + arr[i-1];
    if(n % 2 == 0) {
      ans = min(ans, 1+ minStep3(n/2,arr);
    }

    if(n % 3 == 0) {
      ans = min(ans, 1 + minStep3(n/3,arr);
    }
    arr[i] = ans;
  }
}




//------------------------------------------------
int fibUsingRec(int n) {
   if( n == 0 || n == 1) {
       return 1;
   }

   return fib(n-1) + fib(n-2)
}

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
