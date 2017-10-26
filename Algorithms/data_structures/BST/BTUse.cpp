#include <iostream>
#include "BinaryTreeNode.h"
#include "LargestBstReturn.h"
using namespace std;

void print(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	int leftData = root->left == NULL ? -1 : root->left->data;
	int rightData = root->right? root->right->data : -1;

	cout << leftData << "," << rightData << endl;

	print(root->left);
	print(root->right);
}

//problem without including child and parent both
//x is best without including root
//y is best including root.
pair<int,int> bestSumInTree(BinaryTreeNode<int>* root) {
  if(root == NULL) {
    pair<int,int> p(0,0);
    return p;
  }
  pair<int,int> bestLeftSum = bestSumInTree(root->left);
  pair<int,int> rightBestSum = bestSumInTree(root->right);
  //including root-> excluding root-included sum of immediate children
  int x = root->data + bestLeftSum.second + bestLeftSum.second;
  int y = max(bestLeftSum.first,rightBestSum.first) + max(bestLeftSum.second,rightBestSum.second);
  pair<int,int> p1(x,y);
  return p1;
}



LargestBstReturn* largestBstInBt(BinaryTreeNode<int>* rootNode) {

  if(rootNode == NULL) {
    LargestBstReturn* largestBstReturn = new LargestBstReturn();
    largestBstReturn->largestBSTHeight = 0;
    largestBstReturn->isBST = true;
    largestBstReturn->max = 0;
    largestBstReturn->min = 0;
    return largestBstReturn;
  }
  LargestBstReturn* largestBstReturn1 = new LargestBstReturn;
  largestBstReturn1->isBST = false;
  largestBstReturn1->max = 0;
  largestBstReturn1->min = 0;
  LargestBstReturn* leftLargestBstReturn = largestBstInBt(rootNode->left);
  LargestBstReturn* rightLargestBstReturn = largestBstInBt(rootNode->right);
  int height = 0;
  if(leftLargestBstReturn->isBST && rightLargestBstReturn->isBST) {
    if(leftLargestBstReturn->max <= rootNode->data <= rightLargestBstReturn->min) {
      largestBstReturn1->isBST = true;
      height = max(leftLargestBstReturn->largestBSTHeight,rightLargestBstReturn->largestBSTHeight) + 1; {
      largestBstReturn1->min = leftLargestBstReturn->min;
      largestBstReturn1->max = rightLargestBstReturn->max;
      }
    } else {
      height = max(leftLargestBstReturn->largestBSTHeight,rightLargestBstReturn->largestBSTHeight);

    }
  } else {
    height = max(leftLargestBstReturn->largestBSTHeight,rightLargestBstReturn->largestBSTHeight);
  }

  return largestBstReturn1;
}

void BstToSortedLinkedList(BinaryTreeNode<int>* root) {
  if(root == NULL) {
    return;
  }
  //root->
}
//
// void BTfromInAndPre(int[] inOrder, int[] preOrder, int start, int end) {
//
//
// }
//

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

// 4 2 1 -1 -1 3 -1 -1 6  5 -1 -1  7 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3  6 -1 -1  7 -1 -1
// 1 2 4 8 10 -1 -1 -1 -1 5 -1 9 -1 11 -1 -1 3 -1 -1
int main() {
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
	BinaryTreeNode<int>* leftNode =
		new BinaryTreeNode<int>(1);
	root->left = leftNode;
	delete root;
	root = takeInput();
	print(root);
  LargestBstReturn* la = largestBstInBt(root);
  std::cout << la->largestBSTHeight << std::endl;
  std::cout << "best sum in tree" << bestSumInTree(root).first<<bestSumInTree(root).second << std::endl;
	//pair<int, int> output = heightDiameter(root);
	//cout << output.first << endl;
	//cout << output.second << endl;
	delete root;
}
