#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* add(BinaryTreeNode<int>* bstRoot, int element) {
	if (bstRoot == NULL) {
		BinaryTreeNode<int>* root = new BinaryTreeNode<int>(element);
		return root;
	}
	if (element < bstRoot->data) {
		bstRoot->left = add(bstRoot->left, element);
	} else {
		bstRoot->right = add(bstRoot->right, element);
	}
	return bstRoot;
}

bool search(BinaryTreeNode<int>* bstRoot, int element) {
	if (bstRoot == NULL) {
		return false;
	}

	if (bstRoot->data == element) {
		return true;
	} else if (element > bstRoot->data) {
		return search(bstRoot->right, element);
	} else {
		return search(bstRoot->left, element);
	}

}

void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int ins,
		int ine, int pres, int pree) {
	if (ins > ine) {
		return NULL;
	}

	int rootData = pre[pres];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	int i = ins;
	while (i <= ine) {
		if (in[i] == rootData) {
			break;
		}
		i++;
	}
	int leftPreS = pres + 1;
	int leftInS = ins;
	int leftInE = i - 1;
	int leftPreE = ;

	int rightPreS = ;
	int rightPreE = pree;
	int rightInS = i + 1;
	int rightInE = ine;
	root->left = buildTree(in, pre, leftInS, leftInE, leftPreS, leftPreE);
	root->right = ;
	return root;

}

void postorder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

void preorder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return;
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

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

int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

int height(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void mirror(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	mirror(root->left);
	mirror(root->right);
	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int,int> p(0,0);
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns = heightDiameter(root->right);
	int option1 = leftAns.first + rightAns.first;
	int option2 = leftAns.second;
	int option3 = rightAns.second;
	int diameter = max(option1, max(option2, option3));
	int height = 1 + max(leftAns.first, rightAns.first);
	pair<int,int> p(height, diameter);
	return p;
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int option1 =  height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(max(option1, option2), option3);
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// 1 2 4 8 10 -1 -1 -1 -1 5 -1 9 -1 11 -1 -1 3 -1 -1
int main() {
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
	BinaryTreeNode<int>* leftNode =
		new BinaryTreeNode<int>(1);
	root->left = leftNode;
	delete root;
	root = takeInput();
	print(root);
	pair<int, int> output = heightDiameter(root);
	cout << output.first << endl;
	cout << output.second << endl;
	delete root;
}
