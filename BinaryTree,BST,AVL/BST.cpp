/*
Write a menu-driven program to
i. Create a binary search tree
ii. Traverse the tree in any one [in-order, pre-order, and post-order]
iii. Delete a node in the tree (all 3 cases)
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* right;
	struct node* left;
};
struct node* insert_node(struct node* root, int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		return newnode;
		
	}
	else if(val>root->data)
	{
		root->right=insert_node(root->right,val);
	}
	else 
	{
		root->left=insert_node(root->left,val);
		
	}
}
struct node* delete_node(struct node* root, int val)
{
	if(root==NULL)   //root is null
	{
		return root;
	}
	else if(val>root->data)  //val is greater than root
	{
		root->right=delete_node(root->right, val);
	}
	else if(val<root->data)  //val is less than root
	{
		root->left=delete_node(root->left, val);	
	}
	else 
	{
		if(root->left==NULL && root->right==NULL){  //leaf node 
			free(root);
			return NULL;
		}
		else if(root->left==NULL || root->right==NULL){  //one child exist either right or left
			struct node* temp;
			if(root->right=NULL){
				temp=root->left;
				free(root);
				return temp;
			}
			else{
				temp=root->right;
				free(root);
				return temp;
			}
		}
		else{                  //inoder succesor 
			struct node* temp;
			temp=root->right;
			while(temp->left!=NULL){
				
				temp=temp->left;	
			}
			root->data=temp->data;
			root->right=delete_node(root->right, temp->data);
		}
	}
	return root;
}
struct node* preoder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d", root->data);
		preoder(root->left);
		preoder(root->right);
	}
	
}
struct node* inoder(struct node* root)
{
	if(root!=NULL)
	{
		
		inoder(root->left);
		printf("%d", root->data);
		inoder(root->right);
	}
}
struct node* postoder(struct node* root)
{
	inoder(root->left);
	inoder(root->right);
	printf("%d", root->data);
}


int main()
{
	struct node* root=NULL;
	int ch,val;
	while(1)
	{
		printf("\n---MAIN MENU---\n");
    	printf("1.Create a binary tree.\n");
	    printf("2.Delete a node.\n");
	    printf("3.Preoder.\n");
	    printf("4.Inoder.\n");
	    printf("5.Postoder.\n");
	    printf("Exit\n");
	    printf("Enter your choice:");
	    scanf("%d",&ch);
	    
	    switch(ch)
	    {
	    	case 1:
	    		printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                root = insert_node(root, val);
                inoder(root);
                break;
                
            case 2:
            	printf("Enter the element you want to delete:");
            	scanf("%d",&val);
            	root=delete_node(root,val);
            	inoder(root);
            	break;
            
            case 3:
            	printf("Preoder traversal:");
            	preoder(root);
            	break;
            
            case 4:
            	printf("Inoder traversal:");
            	inoder(root);
            	break; 
            	
            case 5:
            	printf("Postoder traversal:");
            	postoder(root);
            	break;
            
            default:
				printf("\n Enter the correct choice!");
				break;
            	
	    	
		}
		
	}	
}
