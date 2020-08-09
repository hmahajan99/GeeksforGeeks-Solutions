// Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.
// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// The expression contains all characters and ^,*,/,+,-.

// Example:
// Input:
// 2
// a+b*(c^d-e)^(f+g*h)-i
// A*(B+C)/D

// Output:
// abcd^e-fgh*+^*+i-
// ABC+*D/

// Approach
// The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.

// Algorithm
// 1. Scan the infix expression from left to right.
// 2. If the scanned character is an operand, output it.
// 3. Else,
// …..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
// …..3.2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
// 4. If the scanned character is an ‘(‘, push it to the stack.
// 5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
// 6. Repeat steps 2-6 until infix expression is scanned.
// 7. Print the output
// 8. Pop and output from the stack until it is not empty.

using namespace std;

int prec(char ch) {
    switch(ch){
        case '(' : return 100;
        case '^' : return 3;
        case '*' :
        case '/' : return 2;
        case '+' :
        case '-' : return 1;
    }
} 

int main(){
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    stack<char> s;
	    str = "(" + str + ")";
	    for(char ch:str){
	        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
	            while(!s.empty()&&s.top()!='('&&prec(s.top())>=prec(ch)){
	                cout<<s.top();
	                s.pop();
	            }
	            s.push(ch);
	        }else if(ch=='('){
	            s.push(ch);
	        }else if(ch==')'){
	            while(s.top()!='('){
	                cout<<s.top();
	                s.pop();
	            }
	            s.pop();
	        }else{
	            cout<<ch;
	        }
	    }
	    cout<<"\n";
	    
	}
	return 0;
}