// Given a singly linked list, find if the linked list is circular or not. 
// A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. 
// An empty linked list is considered as circular.

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head){
    if(!head) return true;
    Node *temp=head; 
    do{
        temp=temp->next;
    }while(temp!=NULL&&temp!=head);
    
    return temp==head;
    
}
