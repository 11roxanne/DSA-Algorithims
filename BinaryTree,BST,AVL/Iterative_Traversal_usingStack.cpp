
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Preorder Traversal - root , left , right 
//For preorder print the root element first after that until the stack is not empty always push the right node first and then then the left node
//and simultaneously pop the the top element in stack.

vector<int> preorderTraversal(TreeNode* root) {
	stack<TreeNode*> st;
	vector<int> ans;
	TreeNode* curr=root;
	
	if(root==NULL){
		return;
	}
	st.push(root);
	
	while(st.empty()!=true){
		curr=st.top();
		st.pop();
		ans.push_back(curr->val;)
				
		if (curr->right) {
            st.push(curr->right);
        }
        if (curr->left) {
            st.push(curr->left);
        }
	}
	
	return ans;
		      
}

// Iterative Inorder Traversal- left , root , right 
//For iterative approach we use a stack and traverse the left subtree push all the elements in to the stack unitl we reach null , 
//whenever we reach null and since stack follows LIFO we will pop and push the top value in the array and then traverse the right subtree and follow the same process.

vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> st;
	vector<int> ans;
	TreeNode* curr=root;
	
	if(root==NULL){
		return;
	}
	
	while(curr!=NULL || st.empty()!=true){
		while(curr!=NULL){
			st.push(curr);
			curr=curr->left;		
		}
		curr=st.top();
		st.pop();
		ans.push_back(curr->val);
		curr=curr->right;	
	}
	return ans;
    
}

// Iterative Postorder Traversal- left, right , root
//We use two stack , the first store all the element and pops the top element into the second stack .We keep doing this by pushing left and right elemet 
//in the first stack and then popping the top element in the second stack.

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans; 
    stack<TreeNode*> st1; // Stack to hold nodes
    stack<TreeNode*> st2; // Second stack to hold nodes for postorder
    TreeNode* curr=root;
    
    if (root == NULL){
    	return ans;
	}
    st1.push(root);

    while (st1.empty()!=true ) {
        curr = st1.top();
        st1.pop(); 
        st2.push(curr); // Push the node onto the second stack

        if (curr->left) {
            st1.push(curr->left);
        }
        if (curr->right) {
            st1.push(curr->right);
        }
    }

    // Now pop all nodes from the second stack to get the postorder traversal
    while (st2.empty()!=true) {
        ans.push_back(st2.top()->val); 
        st2.pop(); 
    }

    return ans;
	
	
    
}
