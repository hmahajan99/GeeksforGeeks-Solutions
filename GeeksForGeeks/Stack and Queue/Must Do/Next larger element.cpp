// Given an array, print the Next Greater Element (NGE) for every element. 
// The Next greater Element for an element x is the first greater element on the right side of x in array. 
// Elements for which no greater element exist, consider next greater element as -1.

// Approach 1 : Brute force 
// A naive solution would be to take a nested loop.
// This can be O(N^2) in worst case.

/***************************************************************************************************************************/

// Approach 2: Using stack

// Time complexity of above program is O(n) as every element is pushed and popped at most once to the stack. 
// So overall constant number of operations are performed per element.

// Iterate over the array from end, store indices in stack, in increasing order of values from the stack top

#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        lli nextGreater[n]; 
        stack<lli> s; // store indices in stack
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&a[i]>=a[s.top()]){
                s.pop();
            }
            nextGreater[i]=(s.empty())?(-1):(a[s.top()]);
            s.push(i);
        }
        for(int i=0;i<n;i++) cout<<nextGreater[i]<<" ";
        cout<<"\n";
    }
	return 0;
}