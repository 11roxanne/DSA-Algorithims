// count number of nodes

#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value) {
	struct node* newNode = new struct node();
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct node* insert(struct node* root, int value) {
	if (root == NULL) {
		return createNode(value);
	}
	if (value < root->data) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right, value);
	}
	return root;
}

int countNodes(struct node* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
	struct node* root = NULL;
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 9);
	root = insert(root, 8);

	int nodeCount = countNodes(root);
	cout << "The number of nodes: " << nodeCount << endl;

	return 0;
}

