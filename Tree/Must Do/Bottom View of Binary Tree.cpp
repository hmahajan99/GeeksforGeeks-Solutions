// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \    /   \
//               5      3  4     25
//                     /    \      
//                   10      14
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. 
// For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.
// For the above tree the output should be 5 10 4 14 25.

// Approach 1: Level Order Traversal + Map
// Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1.
// Also, use a Map which stores key value pair sorted on key.

/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that prints the bottom view.
void bottomView(Node *root){
   queue<pair<Node*,int>> q; // <Node,horizontal dist from root>
   map<int,int> m; // hor dist -> bottomest value
   if(root) q.push({root,0});
   while(!q.empty()){
       auto p = q.front();
       q.pop();
       Node *front = p.first;
       int horDist = p.second;
       m[horDist] = front->data;
       if(front->left) q.push({front->left,horDist-1});
       if(front->right) q.push({front->right,horDist+1});
   }
   for(auto p:m) cout<<p.second<<" ";
}

/***************************************************************************************************************************/

// Approach 2: Pre Order Traversal + Map
// Create a map like, map where key is the horizontal distance and value is a pair(a, b) where a is the value of the node and b is the height of the node. 
// Perform a pre-order traversal of the tree. 
// If the current node at a horizontal distance of h is the first we’ve seen, insert it in the map. 
// Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update in the Map.

