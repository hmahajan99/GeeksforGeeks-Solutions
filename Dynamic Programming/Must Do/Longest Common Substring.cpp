// Given two strings X and Y. The task is to find the length of the longest common substring.

// Approach 1: Brute Force
// A simple solution is to one by one consider all substrings of first string and for every substring check if it is a substring in second string. 
// Keep track of the maximum length substring. There will be O(m^2) substrings and we can find whether a string is subsring on another string in O(n) time. 
// So overall time complexity of this method would be O(n * (m^2))

/***************************************************************************************************************************/

// Approach 2: Using DP, O(m*n) time
// The idea is to find length of the longest common suffix for all substrings of both strings and store these lengths in a table.

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,y;
        cin>>x>>y;
        int ans=0;
        int dp[n+1][m+1];
        // dp[i][j] =  longest common suffix when len(s)=i & len(y)=j i.e x[0...i-1] & y[0...j-1] 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0; 
                else if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        } 
        cout<<ans<<"\n";
    }
	return 0;
}