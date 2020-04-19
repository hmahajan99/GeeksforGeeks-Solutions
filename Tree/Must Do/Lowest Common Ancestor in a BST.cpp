// Given a Binary Search Tree of size N and 2 nodes value n1 and n2, your task is to find the lowest common ancestor(LCA) of the two nodes .
// Note: Duplicates are not inserted in the BST.

// Approach: Recursive, O(h)

// If we are given a BST where every node has parent pointer, then LCA can be easily determined by traversing up using parent pointer and printing the first intersecting node.
// We can solve this problem using BST properties. We can recursively traverse the BST from root. 
// The main idea of the solution is, while traversing from top to bottom, the first node n we encounter with value between n1 and n2, i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2). 
// So just recursively traverse the BST in, if node’s value is greater than both n1 and n2 then our LCA lies in left side of the node, if it’s is smaller than both n1 and n2, then LCA lies on right side. 
// Otherwise root is LCA (assuming that both n1 and n2 are present in BST)

/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;

};
*/

/*You are required to complete this function*/

// The function assumes that both n1 and n2 are present in BST
Node* LCA(Node *root, int n1, int n2){
   if(root->data<min(n1,n2)) return LCA(root->right,n1,n2);
   else if(root->data>max(n1,n2)) return LCA(root->left,n1,n2);
   else return root;
}

/***************************************************************************************************************************/

// Approach 2: Iterative
// The above solution requires O(h) extra space in function call stack for recursive function calls. 
// We can avoid extra space using iterative solution.

/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;

};
*/

/*You are required to complete this function*/

// The function assumes that both n1 and n2 are present in BST
Node* LCA(Node *root, int n1, int n2){
    while(root){
       if(root->data<min(n1,n2)) root=root->right;
       else if(root->data>max(n1,n2)) root=root->left;
       else break;
    }    
    return root;
}
