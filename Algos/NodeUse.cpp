#include <iostream>
#include "NodeLinked.h"
using namespace std;

int length(Node* head) {
  int length = 0;
  while(head != NULL) {
    head = head->next;
    length++;
  }
  return length;
}

//Limked list is one way so a good habbit to keep head.
void print(Node* head) {

  Node* temp = head;
  while (head != NULL) {
    std::cout << head->data<< "-->";
    head = head->next;
  }
  std::cout << std::endl;
}


Node* getLastItem(Node* head) {
  Node* temp = NULL;
  while(head != NULL) {
    if(head->next == NULL) {
      temp = head;
    }
    head = head->next;
  }
  return temp;
}


class DoubleNode {
public:
  Node* head;
  Node* tail;
};

Node* bubbleSort(Node* head) {
  if(head == NULL) {
    return head;
  }
  Node* current = head;
  Node* previous = NULL;
  while(current->next != NULL) {
    if(current->data > current->next->data) {
      Node* cn = current->next;
      Node* cnn = cn->next;
      cn->next = current;
      if(previous != NULL) {
        // previous->next = current->next;
        // current->next = current->next->next;
        // previous->next->next = current;

        previous->next = cn;
        current->next = cnn;
      } else {

      }


    }else {
      previous = current;
      current = current->next;
    }

  }
}

Node* mergeTwoSortedLinkedList(Node* head1, Node* head2) {
  Node* outputHead;
  Node* outputTail;
  Node* h1 = head1;
  Node* h2 = head2;

  if(head1 == NULL) {

  }
  if(h1->data < h2->data) {
    outputHead = h1;
    outputTail = h1;
    h1 = h1->next;
  } else{
    outputHead = h2;
    outputTail = h2;
    h2 = h2->next;
  }
  //outputHead->next = outputTail

  while(h1 != NULL && h2 != NULL) {
    if(h1->data < h2->data) {
      outputTail->next = h1;
      outputTail = h1;
      h1 = h1->next;


    } else {
      outputTail->next = h2;
      outputTail = h2;
      h2 = h2->next;
    }
  }

  while(h1 != NULL) {
    outputTail->next = h1;
    outputTail = h1;
    h1 = h1->next;
  }
  while(h2 != NULL) {
    outputTail->next = h2;
    outputTail = h2;
    h2 = h2->next;
  }
  outputTail->next = NULL;
  return outputHead;
}


//TODO:
Node* midNode(Node* head) {
  if(head == NULL || head->next == NULL) {
    return head;
  }
  int len = length(head);
  Node* slow;
  Node* fast;
  if(len%2 == 0) {
    slow = head;
    fast = head->next;
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
  } else {
    slow = head;
    fast = head;
    while (fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
  }
  return slow;
}


Node* mergeSortLinkedList(Node* head) {
  if(head->next == NULL) {
    return head;
  }

  Node* tail = getLastItem(head);
  //std::cout << "last  node is " << tail->data << std::endl;
  //std::cout << "list is " << std::endl;
  //print(head);
  Node* mid = midNode(head);
  Node* head1 = head;
  Node* tail1 = mid;
  Node* head2 = mid->next;
  Node* tail2 = tail;
  tail1->next = NULL;
  tail2->next = NULL;
  head1 = mergeSortLinkedList(head1);
  head2 = mergeSortLinkedList(head2);

  Node* outNode = mergeTwoSortedLinkedList(head1,head2);
  return outNode;

}


// space complexitity is constant
Node* reverse1(Node* head) {
  Node* current = head;
  Node* prev = NULL;
  while(current != NULL) {
    Node* currentNext = current->next;
    current->next = prev;
    prev = current;
    current = currentNext;
  }
  return prev;
}

//TIme complexitity = O(n)
// Space complexitity = O(n) -> because of recursion
Node* reverse3(Node* head) {
  if(head == NULL || head->next == NULL) {
    return head;
  }
}

//Time complexitity is coming out to be O(n^2)
// To reduce the complextity reduce the times  we are calculating tail
// Make double Node class
Node* reverseLinkedListR(Node* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node* smallOutput = reverseLinkedListR(head->next);
  Node* tail = smallOutput;
  while(tail->next != NULL) {
    tail = tail->next;
  }
  tail->next = head;
  head->next = NULL;
  return smallOutput;
}

// Sum, Print ith elelment , intsert at i.
Node* delete1(Node* head,int position) {
  if(position > length(head)-1) {
    return NULL;
  }
  if(position == 0 && length(head) == 1) {
    return NULL;
  }else if((position == 0) && length(head) >> 1) {
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
    }
  int i = 0;
  Node* temp = head;
  Node* previous = NULL;
  while (i < position) {
    previous = temp;
    temp = temp->next;
    i++;
  }
  previous->next = temp->next;
  delete(temp);
  return head;
}

Node* insertR(Node* head,int position,int element) {
  if(position == 0) {

  }
  Node* smallOutput = insertR(head->next,position-1,element);
  return head;
}

Node* insertI(Node* head,int i,int element) {
    Node* temp = head;
    Node* node = new Node(element);
    int j = 1;

    if(i > length(head)+1) {
      //show some error
      return NULL;
    }
    while(j < i-1) {
      temp = temp->next;
      j++;
    }
    node->next = temp->next;
    temp->next = node;
    if(i == 1) {
      return temp;
    } else{
      return head;
    }
}

void printI(Node* head, int i) {
   int j = 1;

   if(i > length(head)) {
     std::cout << "NULL" << std::endl;
     return;
   }

   while(j < i) {
     head = head->next;
     j++;
   }
   std::cout << head->data << std::endl;
}

int sum(Node* head) {
  int sum = 0;
  while(head != NULL) {
    sum = sum + head->data;
    head = head->next;
  }
  return sum;
}

int lengthR(Node* head) {
  if(head == NULL) {
    return 0;
  }
  int smallLength = lengthR(head->next);
  return 1 + smallLength;
}



// ALlocate dynamically as it will be persisted
// make the last node NULL.
Node* takeInput() {
  // Node* first  = new Node(20);
  // Node* second = new Node(30);
  // Node* third = new Node(40);
  //
  // first->next = second;
  // second->next = third;
  // return first*
  Node* head = NULL;
  Node* tail = NULL;
  int nextElement;
  cin >> nextElement;
  while(nextElement != -1) {
     Node* nextNode = new Node(nextElement);
     if(head == NULL) {
       head = nextNode;
       tail = nextNode;
     } else {
       tail->next = nextNode;
       tail = nextNode;
     }
     cin >> nextElement;
  }
  return head;
}



int main() {
  Node* node = takeInput();
  Node* node1 = mergeSortLinkedList(node);
  print (node);
  print(node1);

  std::cout << "lenght is "<< length(node) << std::endl;
  std::cout <<"mid is "<< midNode(node)->data << std::endl;
  //insertI(node,1,123);
  print(node);
  length(node);
  //Node* node2 = takeInput();

  //Node* node3 = mergeTwoSortedLinkedList(node,node2);
  //print(node3);

  //std::cout << sum(node3) << std::endl;
  /* code */
  return 0;
}
