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

  // delete recursively
  // when the user provide head it delete the whole list
  //Check when deleting the single node.
  ~Node() {
    if(next != null) {
      delete next;
    }
  }

};
