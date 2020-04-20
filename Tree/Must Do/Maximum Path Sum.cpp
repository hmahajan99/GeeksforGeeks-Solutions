// Given a binary tree in which each node element contains a number. 
// Find the maximum possible sum from one leaf node to another.
// The maximum sum path may or may not go through root.
// If one side of root is empty, then function should return minus infinite (INT_MIN in case of C/C++)

// Approach 1: Brute Force
// A simple solution is to traverse the tree and do following for every traversed node X.
// 1) Find maximum sum from leaf to root in left subtree of X
// 2) Find maximum sum from leaf to root in right subtree of X.
// 3) Add the above two calculated values and X->data and compare the sum with the maximum value obtained so far and update the maximum value.
// 4) Return the maximum value.
// The time complexity of above solution is O(n^2)

/***************************************************************************************************************************/

// Approach 2: O(n)
// We can find the maximum sum using single traversal of binary tree. The idea is to maintain two values in recursive calls
// 1) Maximum root to leaf path sum for the subtree rooted under current node. (Return This from function)
// 2) The maximum path sum between leaves (desired output => Use a reference/global variable) 
// For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, and compare the sum with maximum path sum found so far.

/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/

int maxPath;

int maxPathUtil(Node* node){
    // returns max path sum going through node

    // Base cases
    if(!node) return 0;
    if(!node->left&&!node->right) return node->data; // Leaf Node

    int left=maxPathUtil(node->left);
    int right=maxPathUtil(node->right);

    if(node->left&&node->right){
        // If both left and right children exist  
        // Update maxPath in this case only
        int maxPathThroughThisNode = left + node->data + right;
        maxPath = max(maxPath,maxPathThroughThisNode);
    
        int straightLinePath = node->data + max(left,right);
        return straightLinePath;
    }
    
    int straightLinePath = (node->left) ? (left + node->data) : (right + node->data);
    return straightLinePath;
    
} 

int maxPathSum(Node *root) {
    maxPath = INT_MIN;
    maxPathUtil(root);
    return maxPath;
}

// Alternative: Like diameter of tree, return 2 things straightLinePath & maxPath

/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/


pair<int,int> maxPathUtil(Node* node){
    // Base cases
    if(!node) return {0,INT_MIN};
    if(!node->left&&!node->right) return {node->data,INT_MIN}; // Leaf Node

    pair<int,int> l = maxPathUtil(node->left);
    pair<int,int> r = maxPathUtil(node->right);

    if(node->left&&node->right){
        // If both left and right children exist  
        // Use maxPathThroughThisNode in this case only
        int maxPathThroughThisNode = l.first + node->data + r.first;
        int maxPath = max({l.second,r.second,maxPathThroughThisNode});
    
        int straightLinePath = node->data + max(l.first,r.first);
        return {straightLinePath,maxPath};
    }
    
    int straightLinePath = (node->left) ? (l.first + node->data) : (r.first + node->data);
    int maxPath = max({l.second,r.second});
    return {straightLinePath,maxPath};
    
} 

int maxPathSum(Node *root) {
    return maxPathUtil(root).second;
}