// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
// Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that 
// sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

// Approach: DP

#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,W;
        cin>>N>>W;
        int val[N],wt[N];
        for(int i=0;i<N;i++) cin>>val[i];
        for(int i=0;i<N;i++) cin>>wt[i];
        int dp[N+1][W+1]; // dp[n][w] = max val s.t no of items = n & capacity w
        for(int n=0;n<=N;n++){
            for(int w=0;w<=W;w++){
                if(n==0||w==0) dp[n][w]=0;
                else {
                    int exc = dp[n-1][w];
                    int inc = INT_MIN;
                    if(w-wt[n-1]>=0) inc = val[n-1] + dp[n-1][w-wt[n-1]];
                    dp[n][w] = max(inc,exc);
                }
            }
        }
        cout<<dp[N][W]<<"\n";
    }
	return 0;
}