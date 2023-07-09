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

int node_bf(struct node* root)
{
	if (root == NULL) {
		return 0;
	}

	int hl = (root->left != NULL) ? root->left->height : 0;
	int hr = (root->right != NULL) ? root->right->height : 0;

	return hl - hr;
}

struct node* LLrotation(struct node* root)
{
	struct node* p = root;
	struct node* pl = p->left;
	struct node* plr = pl->right;

	pl->right = p;
	p->left = plr;
	p->height = node_height(p);
	pl->height = node_height(pl);

	return pl;
}

struct node* RRrotation(struct node* root)
{
	struct node* p = root;
	struct node* pr = p->right;
	struct node* prl = pr->left;

	pr->left = p;
	p->right = prl;
	p->height = node_height(p);
	pr->height = node_height(pr);

	return pr;
}

struct node* LRrotation(struct node* root)
{
	struct node* p = root;
	struct node* pl = p->left;
	struct node* plr = pl->right;

	pl->right = plr->left;
	p->left = plr->right;

	plr->left = p;
	plr->right = pl;

	pl->height = node_height(pl);
	p->height = node_height(p);
	plr->height = node_height(plr);

	return plr;
}

struct node* RLrotation(struct node* root)
{
	struct node* p = root;
	struct node* pr = p->right;
	struct node* prl = pr->left;

	pr->left = prl->right;
	p->right = prl->left;

	prl->left = p;
	prl->right = pr;

	pr->height = node_height(pr);
	p->height = node_height(p);
	prl->height = node_height(prl);

	return prl;
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

	root->height = node_height(root);

	if (node_bf(root) == 2 && node_bf(root->left) == 1){
		return LLrotation(root);
	}
	else if (node_bf(root) == 2 && node_bf(root->left) == -1){
		return LRrotation(root);
	}
	else if (node_bf(root) == -2 && node_bf(root->right) == -1){
		return RRrotation(root);
	}
	else if (node_bf(root) == -2 && node_bf(root->right) == 1){
		return RLrotation(root);
	}

	return root;
}

void preorder(struct node* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
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

	cout << "Preorder traversal: ";
	preorder(root);
	cout << endl;

	return 0;
}


