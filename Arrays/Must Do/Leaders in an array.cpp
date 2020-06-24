// Given an array of positive integers. Your task is to find the leaders in the array.
// Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
// Also, the rightmost element is always a leader. 

#include<iostream>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        stack<int> s;
        s.push(A[n-1]);
        for(int i=n-2;i>=0;i--){
            if(A[i]>=s.top()) s.push(A[i]);
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<"\n";
    }
	return 0;
}