/* Find the middle node */

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

struct node* middle_node(struct node* head )
{
	
	struct node* q=head;
	struct node* p=head;
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}	
	
	for(int i=0; i<n/2-1 ;i++)
	{
		q=q->next;	
	}
	return q;
	cout<<q->data<<endl;
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
	struct node* q=head;
	int n;
    add_node(2);
    add_node(5);
    add_node(9);
    add_node(1);
    add_node(10);
    add_node(2);
    
    cout << "Original list is: ";
    display();
    struct node* mid = middle_node(head);
    cout<<mid->data<<endl;
    return 0;
}

