// Implement a Queue using 2 stacks s1 and s2 .

// Approach 1: By making enQueue operation costly
// This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. 
// To put the element at top of stack1, stack2 is used.

// enQueue(q, x): Here time complexity will be O(n)
// deQueue(q): Here time complexity will be O(1)

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop(){
    if(s1.empty()) return -1;
    int x = s1.top();
    s1.pop();
    return x;
}

/***************************************************************************************************************************/

// Approach 2: By making deQueue operation costly
// In this method, in en-queue operation, the new element is entered at the top of stack1. 
// In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

// enQueue(q,  x)
//   1) Push x to stack1
// Here time complexity will be O(1)

// deQueue(q)
//   1) If both stacks are empty then error.
//   2) If stack2 is empty
//        While stack1 is not empty, push everything from stack1 to stack2.
//   3) Pop the element from stack2 and return it.
// Here time complexity will be O(n)

// Approach 2 is definitely better than Approach 1.
// Approach 1 moves all the elements twice in enQueue operation, 
// while Approach 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty. 
// So, the amortized complexity of the dequeue operation becomes Θ(1) .


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x){
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int val = (s2.empty())?(-1):(s2.top());
    if(val!=-1) s2.pop();
    return val;
}
