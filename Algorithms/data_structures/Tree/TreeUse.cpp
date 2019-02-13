#include <iostream>
#include "TreeNode.h"
#include <vector>
using namespace std;

int numNodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < root->children.size(); i++) {
		count = count + numNodes(root->children.at(i));
	}
	return 1 + count;
}

int maxOfAllNodes(TreeNode<int>* root,int max = 0) {
  if(root == NULL) {
    return 0;
  }
  //int max = 0;
  for(int i = 0; i < root->children.size(); i++) {
    max =  maxOfAllNodes(root->children.at(i),max);
  }
  //std::cout << "root data is "<< root->data<<"max is --> "<< max << std::endl;
  return (root->data > max)?root->data:max;
}

int heightOfTree(TreeNode<int>* root,int height = 0) {
  if(root == NULL) {
    return 0;
  }
  int maxHeight = 0;
  for(int i = 0; i < root->children.size();i++) {
      if(height == 0) {
        height++;
      }
      height = heightOfTree(root->children.at(i),height);
      maxHeight = max(height, maxHeight)
    }
   return maxheight + 1;

}

void printAllLeaves(TreeNode<int>* root) {
  if(root == NULL) {
    return ;
  }

  for(int i = 0; i < root->children.size();i++) {
    printAllLeaves(root->children.at(i));
  }

  if(root->children.size() == 0) {
    std::cout << root->data << "  ";
  }

}


int sumOfNodes(TreeNode<int>* root) {
  if(root == NULL) {
    return 0;
  }
  int sum = 0;
  for(int i = 0; i < root->children.size(); i++) {
    sum = sum + sumOfNodes(root->children.at(i));
    }
    return root->data + sum;
}

// 1 3 2 0 3 2 5 0 6 0 4 0
TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	cout << "Enter num of children of " << rootData << endl;
	int numChildren;
	cin >> numChildren;
	for (int i = 0; i < numChildren; i++) {
		TreeNode<int>* nextChild = takeInput();
		root->children.push_back(nextChild);
	}
	return root;
}

void print(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		 TreeNode<int> * child = root->children.at(i);
		 cout << child->data << ",";
	}
	cout << endl;

	for (int i = 0; i < root->children.size(); i++) {
		TreeNode<int> * child = root->children.at(i);
		print(child);
	}
}

int main() {
	TreeNode<int>* root = takeInput();
	print(root);
  std::cout << "Sum is ---> " << sumOfNodes(root) << std::endl;
  std::cout << "max is --> "<< maxOfAllNodes(root) << std::endl;
  std::cout << "height is --> "<< heightOfTree(root) << std::endl;
  printAllLeaves(root);

}
