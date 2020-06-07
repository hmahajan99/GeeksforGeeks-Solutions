// Given a set of positive integers. 
// The task is to complete the function maxSubarrayXOR which returns an integer denoting the maximum XOR subset value in the given set.

// Approach: Not Efficient, Brute Force

vector<vector<int>> dp;

int f(int i,int tot,int A[], int n){
    if(i==n) return tot;
    if(dp[i][tot]!=-1) return dp[i][tot];
    int op1 = f(i+1,tot^A[i],A,n);
    int op2 = f(i+1,tot,A,n);
    return dp[i][tot]=max(op1,op2);
}

// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n){
    dp = vector<vector<int>>(55,vector<int>(1000,-1));
    return f(0,0,A,n);
}