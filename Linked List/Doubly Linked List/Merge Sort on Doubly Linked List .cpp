// Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.


/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


void insert(Node* &head,Node* &tail,Node *x){
    if(!head){
        head=tail=x;
    }else{
        tail->next=x;
        x->prev=tail;
        tail=tail->next;
    }
}

Node *merge(Node *h1,Node *h2){

    Node *fh=NULL,*ft=NULL;
    while(h1&&h2){
        if(h1->data<h2->data){
            insert(fh,ft,h1);
            h1=h1->next;
        }else{
            insert(fh,ft,h2);
            h2=h2->next;
        }
    }
    while(h1){
        insert(fh,ft,h1);
        h1=h1->next;
    }
    while(h2){
        insert(fh,ft,h2);
        h2=h2->next;
    }
    
    if(fh) fh->prev=NULL;
    if(ft) ft->next=NULL;
    return fh;
    
}

Node *midpointDLL(Node *head){
    Node *slow=head,*fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct Node *sortDoubly(struct Node *head){
	if(!head||!head->next) return head;
	Node *mid=midpointDLL(head);
	Node *half2=mid->next;
	mid->next=NULL;
	half2->prev=NULL;
	Node *half1=sortDoubly(head);
	half2=sortDoubly(half2);
	Node *newHead=merge(half1,half2);
	return newHead;
	
}
