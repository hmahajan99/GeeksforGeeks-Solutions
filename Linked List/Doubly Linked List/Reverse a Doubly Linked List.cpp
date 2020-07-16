// Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head){
    // USING 3 POINTERS
   if(!head) return NULL;
   Node *curr=head,*prev=NULL;
   while(curr!=NULL){
       Node *next=curr->next;
       curr->next=prev;
       curr->prev=next;
       prev=curr;
       curr=next;
   }
   return prev;
}

// Alternatively

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head){
    // USING 2 POINTERS
   if(!head) return NULL;
   Node *curr=head,*prev=NULL;
   while(curr!=NULL){
       curr->prev=curr->next;
       curr->next=prev;
       prev=curr;
       curr=curr->prev;
   }
   return prev;
}

