

//Level Order NULL
//We use Breadth First Search algorithm , hence we will use Queue which follows FIFO


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



vector<int> levelOrderTraversal(TreeNode* root) {
	vector<int> ans;
	queue<TreeNode*> q;

	
	if(root==NULL){
		return ans;
	}
	q.push(root);
	
	while(q.empty()!=true){
		TreeNode* temp=q.font();
		q.pop();
		ans.push_back(temp->node);
		
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
	return ans;
	
		      
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = levelOrderTraversal(root);
    cout << "Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
