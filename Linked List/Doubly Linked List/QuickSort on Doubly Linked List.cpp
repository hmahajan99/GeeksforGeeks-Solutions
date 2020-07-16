// Sort the given doubly linked list using quicksort. Just complete the partition function using quicksort technique try to solve it in O(1) space.

/* a Node of the doubly linked list */


/*
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

Node* partition(Node *l, Node *h){
    // Here swapping the value in the nodes
    int pivot=l->data,countSmaller=0;
    Node *temp=l->next;
    while(temp!=h->next){
        if(temp->data<pivot) countSmaller++;
        temp=temp->next;
    }
    Node *p=l;
    for(int i=1;i<=countSmaller;i++){
        p=p->next;
    }
    swap(p->data,l->data);
    while(l!=p&&h!=p){
        if(l->data<p->data){
            l=l->next;
        }else if(h->data>=p->data){
            h=h->prev;
        }else{
            swap(l->data,h->data);
        }
    }
    
    return p;
    
}