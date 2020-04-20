// Serialization is to store tree in a file so that it can be later restored. 
// The structure of tree must be maintained. 
// Deserialization is reading tree back from file.

// If given Tree is Binary Search Tree?
// If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder traversal. 
// In case of Binary Search Trees, only preorder or postorder traversal is sufficient to store structure information.

// If given Binary Tree is Complete Tree?
// A Binary Tree is complete if all levels are completely filled except possibly the last level and all nodes of last level are as left as possible (Binary Heaps are complete Binary Tree). 
// For a complete Binary Tree, level order traversal is sufficient to store the tree

// How to store a general Binary Tree?
// A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space twice the size of Binary Tree.
// We can save space by storing Preorder traversal and a marker for NULL pointers.

// Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
// Note: The structure of tree must be maintained.

// Approach 1: Storing level order traversal, with -1 for NULL values of children

/* A binary tree node has data, pointer to left child  and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes the binary tree and stores it in the vector A*/
void serialize(Node *root,vector<int> &A){
    A.clear();
    if(root==NULL) return ;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            A.push_back(-1);            
        }else{
            A.push_back(front->data);
            q.push(front->left);
            q.push(front->right);
        }
    }
}

/*this function deserializes the serialized vector A*/
Node * deSerialize(vector<int> &A){
   Node *root;
   if(A.size()==0) return root = NULL;

   root = new Node(A[0]);
   int i=1;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(A[i]==-1){
            front->left = NULL;
        }else{
            front->left = new Node(A[i]);
            q.push(front->left);
        } 
        i++;
        
        if(A[i]==-1){
            front->right = NULL;
        }else{
            front->right = new Node(A[i]);
            q.push(front->right);
        } 
        i++;   
       
   }
   return root;
}

/***************************************************************************************************************************/

// Approach 2: Storing pre order traversal, with -1 for NULL values of children

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void serializeHelper(Node *root,vector<int> &A){
    if(!root){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serializeHelper(root->left,A);
    serializeHelper(root->right,A);
}


/*this  function serializes the binary tree and stores it in the vector A*/
void serialize(Node *root,vector<int> &A){
    A.clear();
    serializeHelper(root,A);
}

Node* deSerializeHelper(vector<int> &A,int &i){
    if(A[i]==-1){
        i++;
        return NULL;
    }
    
    Node *node = new Node(A[i]);
    i++;
    node->left = deSerializeHelper(A,i);
    node->right = deSerializeHelper(A,i);
    return node;    
}

/*this function deserializes the serialized vector A*/
Node* deSerialize(vector<int> &A){
    int i=0;
    return deSerializeHelper(A,i);
}
