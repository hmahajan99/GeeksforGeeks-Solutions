/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x){
    QueueNode* newNode = new QueueNode(x);
    if(front==NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = rear->next;
    }
}

/*The method pop which return the element poped out of the queue*/
int MyQueue :: pop(){
    if(front==NULL) return -1;
    QueueNode* temp = front;
    int val = front->data;
    front = front->next;
    delete temp;
    return val;
}
