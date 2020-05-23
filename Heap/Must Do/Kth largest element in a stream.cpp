// Given an input stream of n integers, find the kth largest element for each element in the stream.
// For each test case, in a new line, print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

// Approach 1: Brute Force
// A Simple Solution is to keep an array of size k. The idea is to keep the array sorted so that the k’th largest element can be found in O(1) time (we just need to return first element of array if array is sorted in increasing order)
// How to process a new element of stream?
// For every new element in stream, check if the new element is smaller than current k’th largest element. If yes, then ignore it. If no, then remove the smallest element from array and insert new element in sorted order. 
// Time complexity of processing a new element is O(k).

/***************************************************************************************************************************/

// Approach 2: Using min heap / Self Balancing BST

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        priority_queue<int,vector<int>,greater<int>> pqMin;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            
            if(pqMin.size()<k){
                pqMin.push(x);    
            }else if(x>pqMin.top()){
                pqMin.pop();
                pqMin.push(x);   
            } 
            
            if(pqMin.size()<k) cout<<-1<<" ";
            else cout<<pqMin.top()<<" ";
        }
        cout<<"\n";
    }
    
	return 0;
}