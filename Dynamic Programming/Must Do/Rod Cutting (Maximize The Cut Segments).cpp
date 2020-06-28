// Given an integer N denoting the Length of a line segment. 
// You need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. 
// And after performing all cutting operation the total number of cutted segments must be maximum. 

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i-x>=0&&dp[i-x]!=-1) dp[i] = max(dp[i],dp[i-x]+1);
            if(i-y>=0&&dp[i-y]!=-1) dp[i] = max(dp[i],dp[i-y]+1);
            if(i-z>=0&&dp[i-z]!=-1) dp[i] = max(dp[i],dp[i-z]+1);
        }
        
        cout<<dp[n]<<"\n";
    }
	return 0;
}