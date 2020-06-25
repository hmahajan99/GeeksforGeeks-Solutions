// Also see InterviewBit-Solutions/Strings/String search/Minimum Characters required to make a String Palindromic.cpp

// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Approach 1: DP
// The minimum number of insertions in the string str[l…..h] can be given as
// minInsertions(str[l+1…..h-1]) if str[l] is equal to str[h]
// min(minInsertions(str[l…..h-1]), minInsertions(str[l+1…..h])) + 1 otherwise

#include<iostream>
using namespace std;

int dp[50][50];

int findMinInsertions(int i,int j,const string &s){

    if(i==j) return 0;
    if(i+1==j) return s[i]==s[j] ? 0 : 1;
    
    if(dp[i][j]!=-1) return dp[i][j];    
    
    if(s[i]==s[j]) return dp[i][j]=findMinInsertions(i+1,j-1,s);
    else return dp[i][j]=1+min(findMinInsertions(i,j-1,s),findMinInsertions(i+1,j,s));
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    for(int i=0;i<50;i++){
	        for(int j=0;j<50;j++){
	            dp[i][j]=-1;
	        }
	    }
	    cout<<findMinInsertions(0,s.size()-1,s)<<"\n";
	}
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: DP, Variation of Longest Common Subsequence(LCS) concept, ans = n - LCS(s,rev(s))
// If we find out LCS of string and its reverse, we know how many maximum characters can form a palindrome. 
// We need insert remaining characters. Following are the steps.
// Find the length of LCS of input string and its reverse. Let the length be ‘l’.
// The minimum number insertions needed is length of input string minus ‘l’.

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


int findMinInsertions(string s){
    int n = s.size();
    string rev=s;
    reverse(s.begin(),s.end());
    return n - LCS(s,rev);
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<findMinInsertions(s)<<"\n";
	}
	return 0;
}