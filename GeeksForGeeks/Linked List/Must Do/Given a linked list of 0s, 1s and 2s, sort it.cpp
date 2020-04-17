// Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only. 
// The task is to segregate 0s, 1s and 2s linked list such that all zeros segregate to headside, 2s at the end of the linked list and 1s in the mid of 0s and 2s.

// Approach 1
// Traverse the list and count the number of 0s, 1s and 2s. Let the counts be n1, n2 and n3 respectively.
// Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1 and finally n3 nodes with 2.
// The above solution does not work when these values have associated data with them.

/***************************************************************************************************************************/

// Approach 2: By changing links

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

void insertAtBeginning(Node* &head,Node* &tail,Node* node){
    if(head==NULL){
        head=tail=node;
    }else{
        node->next=head;
        head=node;
    }
} 

void insertAtEnd(Node* &head,Node* &tail,Node* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 


// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    Node *sortedHead,*sortedTail,*zeroesTail;
    sortedHead=sortedTail=zeroesTail=NULL;
    Node *temp=head;
    while(temp){
        if(temp->data==0){
            if(zeroesTail==NULL){
                // zeroesTail will be the first 0
                zeroesTail=temp;    
            } 
            Node *next=temp->next; // NEED TO DO THIS SINCE CHANGING TEMP->NEXT BELOW
            insertAtBeginning(sortedHead,sortedTail,temp);    
            temp=next;
        }else if(temp->data==1){
            Node *next=temp->next; // NEED TO DO THIS SINCE CHANGING TEMP->NEXT BELOW
            if(zeroesTail==NULL){
                insertAtBeginning(sortedHead,sortedTail,temp);    
            }else{
                // Insert 1 after zeroesTail
                temp->next=zeroesTail->next;
                zeroesTail->next=temp;
                if(!sortedTail||sortedTail->data==0){
                    sortedTail=temp;
                }
            }    
            temp=next;
        }else if(temp->data==2){
            insertAtEnd(sortedHead,sortedTail,temp);        
            temp=temp->next;
        }
        
    }
    
    if(sortedTail) sortedTail->next=NULL;
    return sortedHead;
    
}

// Alternative, Better code
// Using dummy nodes

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

void insert(Node* &head,Node* &tail,Node* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 


// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    // Create three dummy nodes to point to beginning of three linked lists.  
    // These dummy nodes are created to avoid many null checks.     
    Node *zeroH,*zeroT,*oneH,*oneT,*twoH,*twoT;
    zeroH=zeroT=new Node(-1);
    oneH=oneT=new Node(-1);
    twoH=twoT=new Node(-1);
    Node *temp=head;
    while(temp){
        if(temp->data==0) insert(zeroH,zeroT,temp);
        else if(temp->data==1) insert(oneH,oneT,temp);
        else if(temp->data==2) insert(twoH,twoT,temp);
        temp=temp->next;
    }
    
    // Attach three lists 
    zeroT->next=(oneH->next)?(oneH->next):(twoH->next);
    oneT->next=twoH->next;
    twoT->next=NULL;
    // Updated head 
    Node *sortedHead=zeroH->next;
    // Delete dummy nodes
    delete zeroH;
    delete oneH;
    delete twoH;
    return sortedHead;

}
