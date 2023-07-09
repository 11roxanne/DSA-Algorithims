#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to perform recursive inorder traversal of the binary tree
void inorderRecursive(struct Node *root)
{
    if (root != NULL)
    {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

// Function to perform non-recursive inorder traversal of the binary tree
void inorderNonRecursive(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    while (1)
    {
        while (root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }
        if (top != -1)
        {
            root = stack[top--];
            printf("%d ", root->data);
            root = root->right;
        }
        else
        {
            break;
        }
    }
}

// Function to perform recursive preorder traversal of the binary tree
void preorderRecursive(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// Function to perform non-recursive preorder traversal of the binary tree
void preorderNonRecursive(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        root = stack[top--];
        printf("%d ", root->data);
        if (root->right != NULL)
        {
            stack[++top] = root->right;
        }
        if (root->left != NULL)
        {
            stack[++top] = root->left;
        }
    }
}

// Function to perform recursive postorder traversal of the binary tree
void postorderRecursive(struct Node *root)
{
    if (root != NULL)
    {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform non-recursive postorder traversal of the binary tree
void postorderNonRecursive(struct Node *root)
{
    struct Node *stack1[100];
    struct Node *stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1)
    {
        root = stack1[top1--];
        stack2[++top2] = root;
        if (root->left != NULL)
        {
            stack1[++top1] = root->left;
        }
        if (root->right != NULL)
        {
            stack1[++top1] = root->right;
        }
    }
    while (top2 != -1)
    {
        root = stack2[top2--];
        printf("%d ", root->data);
    }
}
int main()
{
    struct Node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert node");
        printf("\n2. Recursive inorder traversal");
        printf("\n3. Non-recursive inorder traversal");
        printf("\n4. Recursive preorder traversal");
        printf("\n5. Non-recursive preorder traversal");
        printf("\n6. Recursive postorder traversal");
        printf("\n7. Non-recursive postorder traversal");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("\nInorder traversal (recursive): ");
            inorderRecursive(root);
            break;
        case 3:
            printf("\nInorder traversal (non-recursive): ");
            inorderNonRecursive(root);
            break;
        case 4:
            printf("\nPreorder traversal (recursive): ");
            preorderRecursive(root);
            break;
        case 5:
            printf("\nPreorder traversal (non-recursive): ");
            preorderNonRecursive(root);
            break;
        case 6:
            printf("\nPostorder traversal (recursive): ");
            postorderRecursive(root);
            break;
        case 7:
            printf("\nPostorder traversal (non-recursive): ");
            postorderNonRecursive(root);
            break;
        case 8:
            printf("\nExiting program");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again");
        }
    }
    return 0;
}

