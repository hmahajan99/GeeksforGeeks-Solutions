// Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

/* structure for a node */
/*
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
 
// This function should return head of the modified list
Node *sortedInsert(Node* head, int x){
   if(!head){
       // Empty List
      head = new Node(x);
      head->next=head;
      return head;
   } 
   if(x<head->data){
       // Insertion at begining
       Node *newNode = new Node(x);
       newNode->next=head;
       Node *temp=head;
       while(temp->next!=head){
           temp=temp->next;
       }
       temp->next=newNode;
       return head=newNode;
   }
   Node *temp=head;
   while(x>temp->next->data&&temp->next!=head){
       temp=temp->next;
   }
   Node *newNode = new Node(x);
   newNode->next=temp->next;
   temp->next=newNode;
   return head;
}