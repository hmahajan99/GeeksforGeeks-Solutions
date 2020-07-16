// Given a circular linked list, your task is to complete the method printList() that prints the linked list.


/* structure for a node 
struct Node
{
    int data;
    struct Node *next;
}; */

/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head){
    if(!head) return;
    struct Node *temp = head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

