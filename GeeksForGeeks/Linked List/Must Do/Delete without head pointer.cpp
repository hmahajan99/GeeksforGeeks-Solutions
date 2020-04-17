// You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
// The task is to delete the node. Pointer/ reference to head node is not given.

// It would be a simple deletion problem from the singly linked list if the head pointer was given because for deletion you must know the previous node and you can easily reach there by traversing from the head pointer. 
// Conventional deletion is impossible without knowledge of the previous node of a node which needs to be deleted.

// Approach 1: Change the node which the pointer points to, to the next node 
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node){
    *node=*(node->next); 
}

/***************************************************************************************************************************/

// Approach 2: Copy the data from the next node to the node to be deleted and delete the next node
// This solution doesn’t work if the node to be deleted is the last node of the list. 
// To make this solution work we can mark the end node as a dummy node. 
// But the programs/functions that are using this function should also be modified.

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node){
    node->data=node->next->data;
    Node *temp=node->next;
    node->next=node->next->next;
    delete temp;
}
