// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
// It is given that all array elements are distinct.

// Approach 1: Using Max-Heap, O(nlogk)

#include<iostream>
#include<queue>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    FIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        int k;
        cin>>k;
        priority_queue<int> maxPq;
        for(int i=0;i<n;i++){
            if(maxPq.size()<k){
                maxPq.push(A[i]);
            }else if(A[i]<maxPq.top()){
                maxPq.pop();
                maxPq.push(A[i]);
            }
        }
        cout<<maxPq.top()<<"\n";
        
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using Min-Heap, O(n+klogn)
// Create a Min Heap of the given n elements and call extractMin() k times.
// Building heap takes O(n) here as passing elements in constructor

#include<iostream>
#include<queue>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    FIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        int k;
        cin>>k;
        priority_queue<int,vector<int>,greater<int>> minPq(A,A+n); // Building heap takes O(n) here as passing elements in constructor
        for(int i=1;i<k;i++) minPq.pop();
        cout<<minPq.top()<<"\n";

    }
	return 0;
}