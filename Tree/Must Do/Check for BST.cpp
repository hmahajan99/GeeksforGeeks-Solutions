// Given a binary tree, return true if it is BST, else false. 

// NOTE: How to handle duplicates in Binary Search Tree?
// A Simple Solution is to allow same keys on right side (we could also choose left side).
// A Better Solution is to augment every tree node to store count together with regular fields like key, left and right pointers. 
// The 2nd approach has the advantage height of tree is small irrespective of number of duplicates.

// Approach 1: Recursive

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

class ReturnVal{
public:
    bool isBST;
    int min;
    int max;
    ReturnVal(bool isBst,int min,int max): isBST(isBst),min(min),max(max) {} 
};

ReturnVal isBSTUtil(Node* root){
    if(root==NULL) return {true,INT_MAX,INT_MIN};
    ReturnVal l = isBSTUtil(root->left);
    ReturnVal r = isBSTUtil(root->right);
    bool isBST = l.isBST && r.isBST && (l.max<root->data&&root->data<=r.min);
    int minimum = min({root->data,l.min,r.min});
    int maximum = max({root->data,l.max,r.max});
    return {isBST,minimum,maximum};
}

bool isBST(Node* root) {
    return isBSTUtil(root).isBST;
}

/***************************************************************************************************************************/

// Approach 2: Recursive, maintaining possible range of values i.e. [min,max] for a node

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

bool isBSTHepler(Node* root,int min=INT_MIN,int max=INT_MAX) {
    if(root==NULL) return true;
    if(root->data<min||root->data>max) return false;
    bool l = isBSTHepler(root->left,min,root->data-1);
    bool r = isBSTHepler(root->right,root->data,max);
    return l && r;
}


bool isBST(Node* root) {
    return isBSTHepler(root);
}

/***************************************************************************************************************************/

// Approach 3: Inorder traversal should be sorted in increasing order
// WILL NOT WORK FOR DUPLICATES, Example:
//           2        NOT A BST
//         /   \
//        2     4
//       / \    /
//      1   2  2  

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

bool isBSTHepler(Node* root,int &prev) {
    if(root==NULL) return true;

    if(!isBSTHepler(root->left,prev)) return false;

    if(root->data<=prev) return false; // Allows only distinct valued nodes
    prev = root->data;

    if(!isBSTHepler(root->right,prev)) return false;
    
    return true;
}


bool isBST(Node* root) {
    int prev = INT_MIN;
    return isBSTHepler(root,prev);
}

    