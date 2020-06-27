// Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

// Example:
// Input:
// 2
// 7
// 1 101 2 3 100 4 5
// Output:
// 106

// Explanation:
// Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). 
// Out of these (1, 2, 3, 100) has maximum sum,i.e., 106

// Approach: DP, Variation of Longest Increasing Subsequence(LIS)

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
        int ans;
        int dp[n]; // dp[i] - maximum sum of all increasing subsequence ending at A[i]
        ans=dp[0]=A[0];
        for(int i=1;i<n;i++){
            dp[i]=A[i];
            for(int j=i-1;j>=0;j--){
                if(A[j]<A[i]) dp[i] = max(dp[i],dp[j]+A[i]);
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }
	return 0;
}