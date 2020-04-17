// You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

// Approach 1 : Using Hashing, maintain a list of nodes already visited

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head){
    unordered_set<Node*> vis;
    Node *prev=NULL;
    Node *temp=head;
    while(temp!=NULL){
        if(!vis.count(temp)){
            vis.insert(temp);
            prev=temp;
            temp=temp->next;
        }else{
            prev->next=NULL;
            return;
        }
    }
}

/***************************************************************************************************************************/

// Approach 2 : 2 pointer approach ( Floyd’s Cycle-Finding Algorithm ) 

  //          -------------------
  //          |                 |
  // X->X->X->X->X->X->X->X->X->X
  // <--m-----><-----k--->^
  //                      |
  //                 slow/fast meet

// Note that before meeting the point shown above, fast was moving at twice speed.
// Distance traveled by fast pointer = 2 * (Distance traveled by slow pointer)
// (m + n*x + k) = 2*(m + n*y + k)
// m -->  Distance of first node of cycle from head
// n -->  Length of cycle
// k -->  Distance of point where slow & fast meet from first node of cycle
// x -->  Number of complete cyclic rounds made by fast pointer before they meet first time
// y -->  Number of complete cyclic rounds made by slow pointer before they meet first time

// m + k = (x-2y)*n
// Which means m+k is a multiple of n. 

// So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. 
// When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. 
// Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. 
// Can they meet before also? No because slow pointer enters the cycle first time after m steps.

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head){
    Node *slow=head,*fast=head;
    bool loop = false;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loop = true;
            break;
        } 
    }
    
    if(!loop) return;

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    
    // slow==fast represents the starting point of loop now
    
    Node *temp=slow;
    while(temp->next!=slow){
        temp=temp->next;
    }
    temp->next=NULL;
}

