// Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

void deleteNode(Node **head_ref, int x){
  Node *temp=*head_ref;
  for(int i=1;i<=x-1;i++){
      temp=temp->next;
  }
  if(x==1) *head_ref=(*head_ref)->next; // Head changes
  if(temp->prev) temp->prev->next=temp->next;
  if(temp->next) temp->next->prev=temp->prev;
  delete temp;
    
}