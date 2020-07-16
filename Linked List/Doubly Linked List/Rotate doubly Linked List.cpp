// Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. 
// Here P is a given positive integer and is smaller than the count of nodes(N) in a linked list.

/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node*update(struct node*start,int p){
    node *head=start;
    node *nTail=head ;
    for(int i=1;i<=p-1;i++){
        nTail=nTail->next;
    }
    node *nHead=nTail->next;
    node *tail=nHead;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    
    head->prev=tail;
    nTail->next=NULL;
    nHead->prev=NULL;
    tail->next=head;
    return nHead;
}