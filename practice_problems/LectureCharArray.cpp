//Write a func to get substring of a string
#include<iostream>
using namespace std;

// 1 int getsubstring(char a[],int start,int end) {
//   char ans[100];
//   int j = 0;
//    for (int i = start; i <= end;i++) {
//      ans[j] = a[i];
//      j++;
//    }
//   ans[j] = '\0';
//   cout << ans << endl;
//   return 0;
// }
//
// int main() {
//   char in[100];
//   int start,end;
//   cin.getline(in,100);
//   cout << "Enter starting index " << endl;
//   cin >> start;
//   cout << "enter the ending index  "<< endl;
//   cin >> end;
//   getsubstring(in,start,end);
//
// }



// 2 QUESTION : print all the substring of a substring
// int getsubstring(char a[],int start,int end) {
//   char ans[100];
//   int j = 0;
//    for (int i = start; i <= end;i++) {
//      ans[j] = a[i];
//      j++;
//    }
//   ans[j] = '\0';
//   cout << ans << endl;
//   return 0;
// }
//
//
// int length(char a[]) {
//   int i = 0;
//   while(a[i] != '\0') {
//     i++;
//   }
//   return i;
// }
//
// int getAllSubstring(char sub[]) {
//   int len = length(sub);
//   cout<< "length is " << len << endl;
//   for (int i = 0; i < len; i++) {
//     for (int j = i; j < len; j++) {
//         getsubstring(sub,i,j);
//     }
//   }
//   return 0;
// }
// int main() {
//   char in[100];
//   cout << "Enter the string" << std::endl;
//     //int start,end;
//   cin.getline(in,100);
//     //cout << "Enter starting index " << endl;
//     //cin >> start;
//     //cout << "enter the ending index  "<< endl;
//     //cin >> end;
//   getAllSubstring(in);
//   return 0;
// }



//3 : Question is
// finding the duplicated of string


// int length(char a[]) {
//   int i = 0;
//   while(a[i] != '\0') {
//     i++;
//   }
//   return i;
// }
//
// int removingRepetativeChars(char in[]) {
//   int i = 0;
//   while(in[i] != '\0') {
//     if(in[i] == in[i+1]) {
//       int j = i+1;
//       int len = length(in);
//       while(j < len) {
//         in[j] = in[j+1];
//         j++;
//       }
//
//     } else {
//       i++;
//     }
//   }
//   cout << in << endl;
// }
//
// int main() {
//   char in[100];
//   cout << "Enter the string" << std::endl;
//     //int start,end;
//   cin.getline(in,100);
//     //cout << "Enter starting index " << endl;
//     //cin >> start;
//     //cout << "enter the ending index  "<< endl;
//     //cin >> end;
//   removingRepetativeChars(in);
//   return 0;
// }

//Question : reverse the string
// this is
// output is : siht si

int length(char a[]) {
  int i = 0;
  while(a[i] != '\0') {
    i++;
  }
  return i;
}


int getsubstring(char a[],int start,int end,char ans[]) {
  int j = 0;
   for (int i = start; i <= end;i++) {
     ans[j] = a[i];
     j++;
   }
  ans[j] = '\0';

  return 0;
}

int reverseWords(char in[]) {
  char out[100];
  int l = length(in);
  int a = l-1;
  int i = 0;
  while (a >=0) {
    out[i] = in[a];
    a--;
    i++;
  }
  cout << out << " ";
}

int main() {
  char a[100];
  //cin.getline(a,100);
  cin.getline(a,100);
  //std::cout << "a is "<< a   << std::endl;
  int i = 0;
  int j = 0;
    while(a[i] != '\0') {
      //std::cout << "a[i] is "<<a[i] << std::endl;
      if(a[i] == ' ') {
        //std::cout << "i is " << i << "j is " << j << std::endl;
          char b[100];
          getsubstring(a,j,i-1,b);
          reverseWords(b);
          j = i+1;
        }
      i++;
    }
    char c[100];
    getsubstring(a,j,i-1,c);
    reverseWords(c);
  //cout << a;

}
