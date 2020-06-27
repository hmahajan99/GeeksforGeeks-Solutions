// You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:
// Double the number
// Add one to the number

// Approach 1: DP

#include<iostream>
using namespace std;
int main(){
    int dp[10005];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=10000;i++){
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = min(dp[i],1 + dp[i/2]);
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

/***************************************************************************************************************************/

// Approach 2: Binary Representation
// Calculate the binary equivalent and try moving backwards, ie to subtract 1 and divide by 2 to reach 0 from the given number. 
// Number of subtractions = Number of set bits in the binary equivalent
// Number of divisions = Length of the binary equivalent