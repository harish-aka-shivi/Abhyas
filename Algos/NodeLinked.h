class Node{

public:
  // 4 byte int
  int data;
  // 8 byte pointer
  Node* next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }

};
