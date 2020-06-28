// Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

// Approach 1: Top Down DP
// Consider two cases
// Include the last element 
// Exclude the last element

// isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) ||   isSubsetSum(set, n-1, sum-set[n-1])
// Base Cases:
// isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0
// isSubsetSum(set, n, sum) = true, if sum == 0 

#include<bits/stdc++.h>
using namespace std;

int dp[100][100000];

bool isSubsetSum(int i,int sum,int arr[],int n){
    if(sum<0) return false;
    if(i==n) return sum==0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    return dp[i][sum] = isSubsetSum(i+1,sum,arr,n) || isSubsetSum(i+1,sum-arr[i],arr,n);
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
        if(sum&1){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<100000;j++){
                dp[i][j]=-1;
            }
        }
        if(isSubsetSum(0,sum/2,a,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP
// Space Optimization - can be optimised to O(sum) space

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int i,int sum,int arr[],int n){
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
    return dp[n][sum];
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
        if(sum&1){
            cout<<"NO\n";
            continue;
        }
        if(isSubsetSum(0,sum/2,a,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}