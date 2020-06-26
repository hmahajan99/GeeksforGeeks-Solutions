// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. 
// Output your answer mod 10^9 + 7.

// Approach 1: DP
// We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1. 
// This yields the recurrence relation: f(n) = f(n-1) [append 0] + f(n-2) [append 1]

#include<iostream>
using namespace std;

int dp[150];

int countStrings(int n){
    if(n==1) return 2;
    if(n==2) return 3;
    
    if(dp[n]!=-1) return dp[n];
    
    return dp[n] = ((long)countStrings(n-1) + countStrings(n-2))%((long)1e9+7);
    
}

int main(){
    int t;
    cin>>t;
    fill(dp,dp+110,-1);
    while(t--){
        int n;
        cin>>n;
        cout<<countStrings(n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using Digit DP
// TODO
