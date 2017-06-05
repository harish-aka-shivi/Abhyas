#include <vector>
using namespace std;
template<typename T>
class TreeNode {
public:
  T data;
  // make it pointer to allocate it dynamically
  vector<TreeNode*> children;

  TreeNode(T data) {
    this->data = data;

  }

};
