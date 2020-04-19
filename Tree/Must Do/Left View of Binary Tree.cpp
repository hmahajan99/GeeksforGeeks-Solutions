// Given a Binary Tree, print Left view of it. 
// Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 

//         4
//        / \
//       5   2
//          / \
//         3   1    
//        / \
//       6   7
// Left View: 4 5 3 6    
   
// Approach 1: Using simple recursive traversal
// The idea is to keep track of the maximum level also. 
// Whenever we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level. 

/* A binary tree node

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

int maxDepth;

void leftViewUtil(Node *root,int depth){
    if(!root) return;
    if(depth>maxDepth){
        cout<<root->data<<" ";
        maxDepth=depth;
    }
    leftViewUtil(root->left,depth+1);
    leftViewUtil(root->right,depth+1);
}

// A wrapper over leftViewUtil()
void leftView(Node *root){
    maxDepth=-1;
    leftViewUtil(root,0);
}

/***************************************************************************************************************************/

// Approach 2: Level Order Traversal, Iterative
// The idea is to do level order traversal of the Tree using a queue and print the first node at each level.
// While doing level order traversal, after traversing all node at each level, push a NULL delimiter to mark the end of the current level. 

/* A binary tree node

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

// A wrapper over leftViewUtil()
void leftView(Node *root){
    queue<Node*> q;
    if(root){
        q.push(root);
        q.push(NULL);
    }
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        while(q.front()!=NULL){
            Node *front=q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        q.pop();
        if(!q.empty()) q.push(NULL);
    }
}
