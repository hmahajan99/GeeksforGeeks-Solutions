// Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. 
// Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Example:
// Input:
// 2
// 1
// 1
// 5
// 1 3 5 2 2

// Output:
// 1
// 3

// Explanation:
// Testcase 1: Since its the only element hence its the only equilibrium point.
// Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).

// Approach 1: Using suffix & prefix arrays, O(n) time & O(n) space

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        int prefixSum[n],suffixSum[n];
        prefixSum[0]=suffixSum[n-1]=0;
        for(int i=1;i<n;i++) prefixSum[i] = prefixSum[i-1] + A[i-1];
        for(int i=n-2;i>=0;i--) suffixSum[i] = suffixSum[i+1] + A[i+1];
        bool sol = false;
        for(int i=0;i<n;i++){
            if(prefixSum[i]==suffixSum[i]){
                cout<<i+1<<"\n";
                sol = true;
                break;
            }     
        } 
        if(!sol) cout<<-1<<"\n";
    }

	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using O(n) time & O(1) space

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        int rightSum = accumulate(A,A+n,0);
        int leftSum = 0;
        bool sol = false;
        for(int i=0;i<n;i++){
            rightSum-=A[i];
            if(leftSum==rightSum){
                cout<<i+1<<"\n";
                sol = true;
                break;
            }     
            leftSum+=A[i];
        } 
        if(!sol) cout<<-1<<"\n";
    }

	return 0;
}