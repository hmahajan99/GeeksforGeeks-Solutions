// Given a Cirular Linked List split it into two halves circular lists. 
// If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, 
// first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref){
    if(!head||!head->next) return;
    Node *slow=head,*fast=head->next;
    while(fast!=head&&fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next=*head1_ref;
    Node *temp=*head2_ref;
    while(temp->next!=head) temp=temp->next;
    temp->next=*head2_ref;
}