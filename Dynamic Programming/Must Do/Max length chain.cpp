// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
// A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
// Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

// Approach 1: Greedy, Variation of Activity Selection Problem
// Time O(nlogn)

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n){
    sort(p,p+n,[&](val v1, val v2){
        return v1.second<v2.second;
    });
    
    int ans=0;
    int end = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(p[i].first>end){
            end = p[i].second;
            ans++;
        }
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: DP, O(n^2)
// Variation of Longest Increasing Subsequence problem

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n){
    sort(p,p+n,[&](val v1, val v2){
        return v1.first<v2.first;
    });

    int dp[n]; // dp[i] = Length of longest chain ending at p[i]
    fill(dp,dp+n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].first>p[j].second){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }    
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
    
}