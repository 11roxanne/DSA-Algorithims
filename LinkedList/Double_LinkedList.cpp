#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* insert_beg(struct node* head, int value) {
    struct node* newnode = new struct node();
    newnode->data = value;
    newnode->next = newnode->prev= head ;

    return newnode;
}

struct node* insert_middle(struct node* head, int value, int pos) {
    struct node* newnode = new struct node();
    newnode->data = value;
    newnode->next = newnode->prev=NULL;

    struct node* ptr = head;
    struct node* temp=head;

    if (head==NULL) {
        return newnode;
    }
    else {
        for (int i = 0; i < pos - 2; i++) 
		{ 
		   ptr=ptr->next;
		}
		temp=ptr->next;
		temp->prev=newnode;
		ptr->next=newnode;
		newnode->next=temp;
		newnode->prev=ptr;   
    }
    return head;
}
struct node* insert_end(struct node* head, int value)
{
	struct node* newnode = new struct node();
    newnode->data = value;
    newnode->next = newnode->prev=NULL;
	struct node* ptr = head;
	if(head==NULL){
		cout<<"No nodes exist";
	}
	else{
		while(ptr->next!=NULL){
			ptr=ptr->next;	
		}
		ptr->next=newnode;
		newnode->prev=ptr;
		newnode->next=NULL;
	}
	return head;
	
}
struct node* delete_beg(struct node* head)
{
	if(head==NULL){
		cout<<"List doesnt exist";
	}
	else{
		struct node* temp=head;
		head=head->next;
		delete(temp);
		temp=NULL;
		head->prev=NULL;
	}
	return head;
}

struct node* delete_middle(struct node* head, int pos)
{
	struct node* ptr=head;
	struct node* temp=NULL;
	if(head==NULL){
		cout<<"List doesnt exist";
	}
	else{
		for(int i=0;i<pos-1;i++){
			temp=ptr;
			ptr=ptr->next;	
		}
		temp->next=ptr->next;
		ptr->next->prev=temp;
		delete(ptr);	
	}
	return head;
	
}
struct node* delete_end(struct node* head)
{
	struct node* ptr=head;
	struct node* temp=NULL;

	while(ptr->next!=NULL){
		ptr=ptr->next;
		temp=ptr;
	}
	temp->next=NULL;
	delete(ptr);
	return head;
	
}
int sum(struct node* ptr)
{
	ptr=head;
	int sum=0;
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr=ptr->next;
	}
	return sum;
	
}
int count(struct node* ptr)
{
	int count;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	return count;
}
struct node* search(struct node* head, int X)
{
	struct node* ptr=NULL;
	while(ptr!=NULL)
	{
		if(ptr->data==X)
		{
			return ptr;
		}
		else{
			ptr=ptr->next;
		}	
	}
}
struct node* delete_duplicate(struct node* head)
{
	struct node* p=head;
	struct node* q=head->next;
	if(p->data!=q->data){
		p=q;
		q=q->next;
	}
	else{
		p->next=q->next;
		delete(q);
		q=p->next;
	}

}
struct node* reverse(struct node* head)
{
	struct node* p=head;
	struct node* q=NULL;
	struct node* r=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	head=q;
}
struct node* sum_list(struct node* head1, struct node* head2, int v1, int v2)
{
	struct node* first= new struct node();
	first->data=v1;
	first->next=NULL;
	if(head1==NULL){
		head1=first;
	}
	else
	{
		struct node* ptr1=head1;
		while(ptr1->next!=NULL){
			ptr1=ptr1->next;
		}
		ptr1->next=first;
		
	}
	return head1;
	
	struct node* second= new struct node();
	second->data=v2;
	second->next=NULL;
	if(head2==NULL){
		head2=second;
	}
	else
	{
		struct node* ptr2=head2;
		while(ptr2->next!=NULL){
			ptr2=ptr2->next;
		}
		ptr2->next=first;
		
	}
	return head2;
	
	struct node* q=head1;
	while(q!=NULL)
	{
		q=q->next;
	}
	q->next=head2;
	
}
void display(struct node* ptr)
 {
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    int ch, value, pos,X;
    int v1, v2;
    while (1) {
        cout << "Main Menu\n\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at middle\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at middle\n";
        cout << "7. Count the number of nodes\n";
        cout << "8. Sum of number of nodes\n";
        cout << "9. Search for a node\n";
        cout << "10. Sum of two lists\n";
        cout << "11. Reverse a list\n";
        cout<<  "12. Delete Duplicates in the node\n.";
        cout << "13. Display List\n\n";
        cout << "Enter your choice: ";

        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the number: ";
            cin >> value;
            head = insert_beg(head, value);
            display(head);
            break;
        
        case 2:
                cout << "Enter the number: ";
                cin >> value;
                head = insert_end(head, value);
                display(head);
                break;
            
        case 3:
        	cout<<"Enter the number:";
        	cin>>value;
        	cout<<"Enter the position:";
        	cin>>pos;
        	head=insert_middle(head,value,pos);
        	display(head);
        	
        case 4:
                head = delete_beg(head);
                display(head);
                break;

        case 5:
                head = delete_end(head);
                display(head);
                break;

        case 6:
                cout << "Enter the position: ";
                cin >> pos;
                head = delete_middle(head, pos);
                display(head);
                break;

        case 7:
            cout << "Number of nodes: " << count(head) << endl;
            break;

        case 8:
            cout << "Sum of nodes: " << sum(head) << endl;
            break;
        
        case 9:
        	cout<<"Enter the number to be searched:";
        	cin>>X;
        	head=search(head,X);
        	cout<<"The number is found";
        	break;
        	
        case 10:
        	cout<<"Enter the elements of first list:";
        	cin>>v1;
        	cout<<"Enter the elements of first list:";
        	cin>>v2;
        	break ;
        case 11:
        	cout<<"The reversed list is:";
        	head= reverse(head);
        	display(head);
        	break;
        	
        case 12:
        	cout<<"The duplicates have been deleted";
        	head = delete_duplicate(head);
			display(head);
			break;
		        	
        case 13:
            display(head);
            break;
            
        default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}

