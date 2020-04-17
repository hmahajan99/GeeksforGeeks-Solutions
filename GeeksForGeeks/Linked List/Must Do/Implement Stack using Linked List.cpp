/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

// Need only 1 pointer top 
// Stack =>   3 <-- top
//            2 
//            1
 


/* The method push to push element into the stack */
void MyStack ::push(int x) {
    // Inserting at beginning of list 
    StackNode* newNode = new StackNode(x);
    newNode->next = top;
    top = newNode;
}

/* The method pop which return the element poped out of the stack*/
int MyStack ::pop() {
    if(top==NULL) return -1;
    StackNode* temp = top;
    int val = top->data;
    top = top->next;
    delete temp;
    return val;
}
