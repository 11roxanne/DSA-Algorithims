
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	int height;
};

struct node* root = NULL;

int node_height(struct node* root)
{
	if (root == NULL) {
		return 0;
	}

	int hl = (root->left != NULL) ? root->left->height : 0;
	int hr = (root->right != NULL) ? root->right->height : 0;

	return (hl > hr) ? hl + 1 : hr + 1;
}

bool node_bf(struct node* root)
{
	if (root == NULL) {
		return 0;
	}

	int hl = (root->left != NULL) ? root->left->height : 0;
	int hr = (root->right != NULL) ? root->right->height : 0;

	return hl - hr;
	return node_bf(root->left) && node_bf(root->right);	
}

struct node* insert(struct node* root, int value)
{
	if (root == NULL){
		struct node* newnode = new struct node();
		newnode->data = value;
		newnode->height = 1;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
	else {
		if (value > root->data) {
			root->right = insert(root->right, value);
		}
		else {
			root->left = insert(root->left, value);
		}
	}
	
}

int main()
{
	int value, n;
	cout << "Enter the number of nodes: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the node value: ";
		cin >> value;
		root = insert(root, value);
	}
	if(node_bf(root)){
		cout<<"Tree is balanced ";
	}
	else{
		cout<<"Tree is not balanced";
	}
	return 0;
}


