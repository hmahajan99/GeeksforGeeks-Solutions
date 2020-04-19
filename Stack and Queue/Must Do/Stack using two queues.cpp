// Implement a Stack using two queues q1 and q2.

// Approach 1: By making pop operation costly
// In push operation, the new element is always enqueued to q1. 
// In pop() operation, if q2 is empty then all the elements except the last, are moved to q2. 
// Finally the last element is dequeued from q1 and returned.

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x){
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop(){
    if(q1.empty()) return -1;
    while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
    }
    int x = q1.front();
    q1.pop();
    swap(q1,q2);
    return x;
}


/***************************************************************************************************************************/

// Approach 2: By making push operation costly
// This method makes sure that newly entered element is always at the front of ‘q1’, so that pop operation just dequeues from ‘q1’. 
// ‘q2’ is used to put every new element at front of ‘q1’.

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop(){
    if(q1.empty()) return -1;
    int val = q1.front();
    q1.pop();
    return val;
}
