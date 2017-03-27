#include <iostream>
#include "NodeLinked.h"
using namespace std;

class StackUsingLinked {
  Node* head;
  int length;

public:
  StackUsingLinked {
    head = NULL;
    length = 0;
  }

  int size {
    return length;
  }

  void push(int element) {
    Node* temp = new Node(element);
    temp->next = head;
    head = temp;
    length++;
  }

  int pop() {
    if(head == NULL) {
      return -1;
    }
    Node* temp = head;
    head = head->next;
    length--;
    temp->next = NULL;
    int s = temp->data;
    delete temp;
    return s;
  }

  bool isEmpty() {
    return length = 0;
  }

  int top() {
    if(head == NULL) {
      return -1;
    }
    return head->data;
  }


}
