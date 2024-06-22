/*Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.*/

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* add_node(int value) {
    struct node* newnode = new struct node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newnode;
    }
    return head;
}

struct node* nth_node(struct node* head, int n) {
    struct node* p = head;
    struct node* q = head;

    // Move the 'p' pointer n positions ahead
    for (int i = 0; i < n; i++) {
        if (p == NULL) {
            return NULL;  // n is greater than the length of the list
        }
        p = p->next;
    }

    // Move both pointers until the 'p' pointer reaches the end
    while (p != NULL) {
        p = p->next;
        q = q->next;
    }

    return q;
}

void display(struct node* head) {
    struct node* p = head;
    if (p == NULL) {
        cout << "The list is empty." << endl;
    } else {
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main() {
    int n;
    add_node(2);
    add_node(4);
    add_node(9);
    add_node(1);
    add_node(10);
    add_node(3);

    cout << "Enter the position of the node from the end: ";
    cin >> n;

    cout << "The original list is: ";
    display(head);

    struct node* nthNode = nth_node(head, n);

    if (nthNode != NULL) {
        cout << "The " << n << "th node from the end is: " << nthNode->data << endl;
    } else {
        cout << "Invalid position or the list is empty." << endl;
    }

    return 0;
}

