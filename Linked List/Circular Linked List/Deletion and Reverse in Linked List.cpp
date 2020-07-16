// Given a Circular Linked List of size N. 
// The task is to delete the given node (excluding the first and last node) in circular linked list and then print the reverse of the circular linked list.

/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key){
    Node *temp=*head;
    while(temp->next->data!=key) temp=temp->next;
    Node *d=temp->next;
    temp->next=temp->next->next;
    delete d;
}

/* Function to reverse the linked list */
void reverse(struct Node** head_ref){
    Node *head=*head_ref;
    if(!head) return;
    Node *curr=head->next,*prev=head;
    while(curr!=head){
        Node *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    curr->next=prev;
    *head_ref=prev;
}