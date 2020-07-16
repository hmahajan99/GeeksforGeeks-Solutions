// Given a doubly-linked list, a position p, and an integer x. 
// The task is to add a new node with value x at the position just after pth node in the doubly linked list.

/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

/* Function to insert into a Doubly Linked List */
void addNode(Node *head, int pos, int data){

    Node *temp=head;
    for(int i=1;i<=pos;i++){
        temp=temp->next;
    }
    Node *newNode = new Node(data);
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    if(newNode->next) newNode->next->prev=newNode;
    
}