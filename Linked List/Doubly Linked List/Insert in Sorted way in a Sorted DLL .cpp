// Given a sorted doubly linked list and an element X, your need to insert the element X into correct position in the sorted DLL.

/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node *head, int x){
    Node *newNode = new Node;
    newNode->data=x;
    newNode->next=newNode->prev=NULL;
    if(!head){
        // Empty LL
        return newNode;
    }
    if(newNode->data<head->data){
        // Ins at beg
        newNode->next=head;
        head->prev=newNode;
        return newNode;
    }
    Node *temp=head;
    while(temp->next&&temp->next->data<newNode->data){
        temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    if(newNode->next) newNode->next->prev=newNode;
    return head;
}