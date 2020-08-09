// Given a postfix expression, the task is to evaluate the expression and print the final value. 
// Operators will only include the basic arithmetic operators like *,/,+ and - . 

// Example:
// Input:
// 2
// 231*+9-
// 123+*8-
// Output:
// -4
// -3

// Approach
// The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix. 
// Following is algorithm for evaluation postfix expressions.
// 1) Create a stack to store operands (or values).
// 2) Scan the given expression and do following for every scanned element.
// …..a) If the element is a number, push it into the stack
// …..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
// 3) When the expression is ended, the number in the stack is the final answer


#include<stack>
using namespace std;

int op(int b,int a,char ch){
    switch(ch){
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    string expr;
	    cin>>expr;
	    stack<int> s;
	    for(char ch:expr){
	        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
	            int a=s.top(); s.pop();
	            int b=s.top(); s.pop();
	            s.push(op(b,a,ch));
	        }else{
	            s.push(ch-'0');
	        }
	    }
	    cout<<s.top()<<"\n";
	}
	return 0;
}