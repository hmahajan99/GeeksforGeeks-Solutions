// An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. 
// A memory efficient version of Doubly Linked List can be created using only one space for address field with every node. 
// This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.
// Given stream of data of size N for the linked list, your task is to complete the function insert() and printList(). 
// The insert() function pushes (or inserts at beginning) the given data in the linked list and the printList() function prints the linked list first in forward direction and then in backward direction.
// Note: There is an utility function XOR() that takes two Node pointer to get the bit-wise XOR of the two Node pointer. Use this function to get the XOR of the two pointers.

// Approach
// In the XOR linked list, instead of storing actual memory addresses, every node stores the XOR of addresses of previous and next nodes.
// Traversal of XOR Linked List: We can traverse the XOR list in both forward and reverse direction. 
// While traversing the list we need to remember the address of the previously accessed node in order to calculate the next node’s address.

/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/


// function should insert the data to the front of the list
struct Node* insert(struct Node *head, int data){
	Node *newNode=new Node(data);
	newNode->npx=XOR(NULL,head);
	if(head!=NULL){
	    Node *next=XOR(NULL,head->npx);
	    head->npx=XOR(newNode,next);
	}
	return head=newNode;
}

// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head){
	Node *prev=NULL;
	Node *curr=head;
	while(curr){
	    cout<<curr->data<<" ";
	    Node *next = XOR(curr->npx,prev);
	    prev=curr;
	    curr=next;
	}
	cout<<"\n";
    curr=prev; // Tail
    Node *next=NULL;
	while(curr){
	    cout<<curr->data<<" ";
	    Node *prev = XOR(curr->npx,next);
	    next=curr;
	    curr=prev;
	}
}
