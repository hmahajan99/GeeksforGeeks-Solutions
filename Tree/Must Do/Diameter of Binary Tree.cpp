// Given a Binary Tree, find diameter of it.
// The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
// The diameter may or may not go through root.

// Approach 1: O(n^2) -> optimise to O(n) by calculating height in same recursion
// * the diameter of T’s left subtree
// * the diameter of T’s right subtree
// * the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

pair<int,int> heightDiameter(Node* node){
    if(!node) return {0,0};
    pair<int,int> l = heightDiameter(node->left);
    pair<int,int> r = heightDiameter(node->right);
    int height = 1 + max(l.first,r.first);
    int diameter = max({l.first+1+r.first,l.second,r.second});
    return {height,diameter};
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    return heightDiameter(node).second;
}

// Alternative: Using ,maxDiameter as global/reference variable 

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int maxDiameter;

int height(Node* node){
    if(!node) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    int height = 1 + max(lh,rh);
    maxDiameter = max(maxDiameter,lh+1+rh);
    return height;
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    maxDiameter=INT_MIN;
    height(node);
    return maxDiameter;
}

/***************************************************************************************************************************/

// Approach 2: Diameter of a tree using DFS
// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. 
// After observing above tree we can see that the longest path will always occur between two leaf nodes. 
// We start DFS from a random node and then see which node is farthest from it. 
// Let the node farthest be X. It is clear that X will always be a leaf node and a corner of DFS. 
// Now if we start DFS from X and check the farthest node from it, we will get the diameter of the tree.