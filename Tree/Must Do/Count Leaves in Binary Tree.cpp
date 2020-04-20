// Given a Binary Tree of size N , You have to count leaves in it. 

// Approach 1: Recursive

/* A binary tree node has data, pointer to left child and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return value should be 2 for following tree.
         10
        /  \ 
       20  30 */

int countLeaves(Node* root){
  if(!root) return 0;
  if(!root->left&&!root->right) return 1; // Leaf Node
  return countLeaves(root->left) + countLeaves(root->right);
}


/***************************************************************************************************************************/

// Approach 2: Level Order Traversal, Iterative
// The idea is to use level order traversal. During traversal, if we find a node whose left and right children are NULL, we increment count.