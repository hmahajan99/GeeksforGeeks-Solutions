// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
// The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
// The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
// The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

// Approach: Do inorder traversal of tree and keep inserting in DLL
// NOTE: This is IN-PLACE

/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Insert at end of DLL
void insert(Node* &head,Node* &tail,Node* node){
    if(!head){
        head=tail=node;
    }else{
        tail->right=node;
        node->left=tail;
        tail=node;
    }
}

void inOrderInsert(Node *root,Node* &head,Node* &tail){
    if(!root) return;
    
    inOrderInsert(root->left,head,tail);
    insert(head,tail,root);
    inOrderInsert(root->right,head,tail); // Can do this since root->right not changed in above insert step
}



// This function should convert a given Binary tree to Doubly Linked List
void bToDLL(Node *root, Node **head_ref){
    Node *head,*tail;
    head=tail=NULL;
    inOrderInsert(root,head,tail);
    if(head){
        head->left=NULL;
        tail->right=NULL;
    }
    *head_ref = head;
}
