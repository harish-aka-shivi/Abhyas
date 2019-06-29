#include <iostream>
#include "NodeLinked.h"

class QueueUsingLinked {
  Node* head;
  Node* tail;
  int length;

public:
  QueueUsingLinked {
    head = NULL;
    tail = NULL;
    length = 0;
  }

  void push(int element) {
    Node* temp = new Node(element);
    if(tail == NULL) {
      tail = temp;
      head = tail;
    }
    else {
      tail->next = temp;
      tail = temp;
    }
    length++;
  }
  int pop() {

    if(head == NULL) {
      return -1;
    } else if (length ==  1){
      Node* temp = head;
      int s = temp-> data;
      head->next = NULL;
      tail = NULL;
      delete head;
      length--;
      return s;
    } else {
      Node* temp = head;
      int s = temp-> data;
      head = head->next
      temp->next = NULL;
      delete temp;
      length--;
      return s;
    }
  }

  int length() {
    return length;
  }

  bool isEmpty() {
    return length==0;
  }
  int front() {
    if(head == NULL) {
      return -1;
    }
    return head->data;
  }


}
