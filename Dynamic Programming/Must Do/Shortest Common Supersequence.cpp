// Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.

// Approach
// Length of the shortest supersequence  = (Sum of lengths of given two strings) - (Length of LCS of two given strings)
// We first find the longest common subsequence, take one occurrence of this subsequence and add extra characters ,i.e (lcs + (x-lcs) + (y-lcs))

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2){
    int n1=s1.size(),n2=s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1));
    // dp[i][j] = LCS when len(s1)=i & len(s2)=j i.e s1[0...i-1] & s2[0...j-1]
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0||j==0) dp[i][j]=0;
            else{
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
    return dp[n1][n2];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string x,y;
        cin>>x>>y;
        int lcs = LCS(x,y);
        int ans = x.size()+y.size()-lcs;
        cout<<ans<<"\n";
    }
	return 0;
}