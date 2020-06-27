// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

// It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), 
// and has applications in bioinformatics.

// Approach: DP
// For Space Optimized Solution :- In each iteration of outer loop we only, need values from all columns of previous row. 
// So there is no need of storing all rows in our DP matrix, we can just store two rows at a time and use them

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
        int n,m;
        cin>>n>>m;
        string x,y;
        cin>>x>>y;
        cout<<LCS(x,y)<<"\n";
    }
	return 0;
}