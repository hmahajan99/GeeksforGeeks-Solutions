// Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.

// You have to flatten the linked list to a single linked list which should be sorted.

//        5 -> 10 -> 19 -> 28
//        |    |     |     |
//        V    V     V     V
//        7    20    22    35
//        |          |     |
//        V          V     V
//        8          50    40
//        |                |
//        V                V
//        30               45

// And after flattening the above list, the sorted linked list looks like:

//  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

// Approach: Using Min Heap

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class NodeCompare{
    public:
    bool operator()(Node* A,Node* B){
        return A->data>B->data; // MIN HEAP
    }
} ;

void insert(Node* &head,Node* &tail,Node* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->bottom=node;
        tail=tail->bottom;
    }
} 


/*  Function which returns the  root of the flattened linked list. */
Node *flatten(Node *root){
    // Custom Class in Priority Queue
    priority_queue <Node*, vector<Node*>, NodeCompare > pq;
    Node *temp=root;
    while(temp){
        Node *temp2=temp;
        while(temp2){
            pq.push(temp2);
            temp2=temp2->bottom;
        }
        temp=temp->next;
    }
    
    Node *sortedHead=NULL,*sortedTail=NULL;
    while(!pq.empty()){
        insert(sortedHead,sortedTail,pq.top());
        pq.pop();
    }
    return sortedHead;
}
