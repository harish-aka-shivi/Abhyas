//Given an expression check if brackets are balanced
// For eg. {a+[b+(c+d)]+(e+f)}
#include <iostream>
#include "NodeLinked.h"
#include "StackUsingLinked.h"
#include "StackUsingArray.h"

bool isBalanced(char* input) {
  StackUsingArray s;
  for(int i =0; input[i] != '\0' ; i++) {
    if(input[i] == '(' ||
      input[i] == '[' ||
      input[i] == '{') {
        s.push()
      }
  }
}

void reverseStack(StackUsingLinked* s1, StackUsingLinked* s2) {
  int top = s1->pop();
  if(top == -1) {
    return
  }
  ret

}

int main() {

}
