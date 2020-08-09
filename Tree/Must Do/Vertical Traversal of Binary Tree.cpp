// You are given a binary tree for which you have to print its vertical order traversal. 
// Your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order as shown below.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal.

// Note: This question is tagged as BST because to solve the questions efficiently, we need to use an ordered map (map in C++ and TreeMap in Java).  
// The ordered maps are mainly implemented using self-balancing-BST.

//              1
//            /   \
//          2      3
//        /  \      \
//       4    5      6
// The output is 4 2 1 5 3 6.

// Approach 1: Level Order Traversal + Map
// Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1.
// Also, use a Map which stores key value pair sorted on key. 


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// root: root node of the tree
void verticalOrder(Node *root){
   queue<pair<Node*,int>> q; // <Node,horizontal dist from root>
   map<int,vector<int>> m; // hor dist -> vertical order for dist
   if(root) q.push({root,0});
   while(!q.empty()){
       auto p = q.front();
       q.pop();
       Node *front = p.first;
       int horDist = p.second;
       m[horDist].push_back(front->data);
       if(front->left) q.push({front->left,horDist-1});
       if(front->right) q.push({front->right,horDist+1});
   }

   for(auto p:m){
       for(int val:p.second) cout<<val<<" ";
   }  
}

/***************************************************************************************************************************/

// Approach 2: Pre Order Traversal + Map
// Since above approach uses preorder traversal, nodes in a vertical line may not be prined in same order as they appear in tree. 
// Example: 5 would be printed before 3 for horizontal dist = +1
//                        1
//                      /  \
//                     2    3
//                      \   
//                       4  
//                        \      
//                         5
