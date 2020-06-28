// A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top

// Approach: DP
// Space Optimization - only the last three states are required (i – 1, i – 2, i – 3). 
// So, the result can be calculated using the last three states.

#include<iostream>
using namespace std;
int main(){
    int dp[55];
    dp[0]=1;
    for(int i=1;i<=50;i++){
        dp[i] = dp[i-1];
        if(i>=2) dp[i] += dp[i-2];
        if(i>=3) dp[i] += dp[i-3];
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
	return 0;
}