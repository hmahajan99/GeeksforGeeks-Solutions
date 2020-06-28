// Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

// Similar to GeeksForGeeks/Dynamic Programming/Must Do/Subset Sum Problem.cpp

// Approach 1: Top Down DP

#include<bits/stdc++.h>
using namespace std;

int dp[51][10001];

int findMin(int i, int currentSum, int totalSum, int arr[], int n) { 
    if(i==n) return abs(currentSum - (totalSum-currentSum)); 
    
    if(dp[i][currentSum]!=-1) return dp[i][currentSum]; 

    int inc = findMin(i+1,currentSum+arr[i],totalSum,arr,n);
    int exc = findMin(i+1,currentSum,totalSum,arr,n);

    return dp[i][currentSum] = min(inc,exc); 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int sum = accumulate(a,a+n,0);
        for(int i=0;i<=50;i++){
            for(int j=0;j<=10000;j++){
                dp[i][j]=-1;
            }
        }
        cout<<findMin(0,0,sum,a,n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP
// Space Optimization - can be optimised to O(sum) space

#include<bits/stdc++.h>
using namespace std;

int findMin(int sum, int arr[], int n) { 
    bool dp[n+1][sum+1]; // dp[i][s] = does arr[0..i-1] i.e len(arr)=i, have a subset with sum = s
    for(int i=0;i<=n;i++){
        for(int s=0;s<=sum;s++){
            if(i==0) dp[i][s] = s==0;
            else {
                dp[i][s] = dp[i-1][s];
                if(s-arr[i-1]>=0) dp[i][s] = dp[i][s] | dp[i-1][s-arr[i-1]];
            }
        }
    }
    
    int ans=INT_MAX;
    for(int s=0;s<=sum/2;s++){
        if(dp[n][s]){
            ans=min(ans,abs(s-(sum-s)));
        }
    }
    return ans;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int sum = accumulate(a,a+n,0);
        cout<<findMin(sum,a,n)<<"\n";
    }
	return 0;
}