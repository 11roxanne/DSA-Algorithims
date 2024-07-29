#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->data << " ";
        q.pop();

        if (curr->left != NULL) {
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }

    return root;
}

int minValue(Node* root) {
    int minv = root->data;
    while (root->left != NULL) {
        minv = root->left->data;
        root = root->left;
    }
    return minv;
}

bool searchNode(Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->data == val) {
        return true;
    }

    if (val < root->data) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Level Order Traversal\n";
        cout << "7. Search\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Level Order Traversal: ";
                levelorderTraversal(root);
                cout << endl;
                break;
            case 7:
                cout << "Enter the value to search: ";
                cin >> value;
                if (searchNode(root, value)) {
                    cout << "Value found in the binary tree.\n";
                } else {
                    cout << "Value not found in the binary tree.\n";
                }
                break;
            case 8:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
