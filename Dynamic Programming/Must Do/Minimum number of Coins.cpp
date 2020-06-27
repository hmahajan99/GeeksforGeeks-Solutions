// Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations 
// in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, 
// Find the minimum number of coins and/or notes needed to make the change for Rs N.

// Example:
// Input:
// 1
// 43

// Output:
// 20 20 2 1

// Approach 1: Greedy
// For Indian Currency greedy always work
// The above approach may not work for all denominations. For example, it doesn’t work for denominations {9, 6, 5, 1} and V = 11.

#include<iostream>
using namespace std;
int main(){
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int numCoins = sizeof(coins)/sizeof(int);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=numCoins-1;i>=0;i--){
            for(int j=1;j<=n/coins[i];j++) cout<<coins[i]<<" ";
            n%=coins[i];
        }
        cout<<"\n";
    }
    
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: DP with PATH RECONSTRUCTION using PARENT ARRAY

#include<iostream>
#include<climits>
using namespace std;

int dp[(int)1e6+5]; // dp[i] = minimum number of coins and/or notes needed to make the change for Rs i
int parent[(int)1e6+5]; // parent[i] = coin changed for Rs i to get min coins

int main(){
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int numCoins = sizeof(coins)/sizeof(int);
    dp[0]=0;
    for(int i=1;i<=1e6;i++){
        dp[i]=INT_MAX;
        for(int j=numCoins-1;j>=0;j--){
            if(i-coins[j]>=0&&dp[i]>1+dp[i-coins[j]]){
                dp[i]=1+dp[i-coins[j]];
                parent[i]=coins[j];
            } 
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        while(n){
            cout<<parent[n]<<" ";
            n-=parent[n];
        }
        cout<<"\n";
    }
    
	return 0;
}