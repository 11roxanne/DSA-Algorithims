#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void addnode(int data) {
    struct node* newnode = new struct node();
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else
    {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void sort() {
    if (head == NULL || head->next == NULL) {
        // Empty list or single node, already sorted
        return;
    }

    struct node* p = head;
    struct node* q = NULL;
    int temp;

    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                // Swap values
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        struct node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main() {
    addnode(2);
    addnode(5);
    addnode(9);
    addnode(1);

    cout << "Original list is: ";
    display();
    
    sort();
    
    cout << "Sorted list is: ";
    display();

    return 0;
}

