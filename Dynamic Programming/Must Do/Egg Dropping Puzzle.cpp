// Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
// You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
// There are few rules given below:-
//   An egg that survives a fall can be used again.
//   A broken egg must be discarded.
//   The effect of a fall is the same for all eggs.
//   If the egg doesn't break at a certain floor, it will not break at any floor below.
//   If the eggs breaks at a certain floor, it will break at any floor above.

// Approach 1: Top Down DP
// The solution is to try dropping an egg from every floor(from 1 to k) and recursively calculate the minimum number of droppings needed in the worst case
// The floor which gives the minimum value in the worst case is going to be part of the solution
// We return the minimum number of trials in the worst case
// Optimal Substructure:
//   When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break
//   1) If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ in which egg would not break, so the problem reduces to x-1 floors and n-1 eggs
//   2) If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs
//   Since we need to minimize the number of trials in worst case, we take the maximum of two cases

// n ==> Number of floors
// e ==> Number of Eggs
// eggDrop(n, e) ==> Minimum number of trials needed to find the critical floor in worst case
// eggDrop(n, e) = 1 + min{max(eggDrop(x–1,e-1), eggDrop(n–x,e)), where x is in {1, 2, …, n}}
// Base Cases
// eggDrop(0, e) = 0, If there are no floors, then no trials needed
// eggDrop(1, e) = 1, if there is one floor, one trial needed.  
// eggDrop(n, 1) = n, We need n trials for one egg and n floors 

// Time Complexity: O(e*n^2)
// Auxiliary Space: O(e*n)

#include<bits/stdc++.h>
using namespace std;

int dp[51][11];

int minAttempts(int n,int e){
    if(n==0) return 0;
    if(n==1) return 1;
    if(e==1) return n;
    
    if(dp[n][e]!=-1) return dp[n][e];
    
    int attempts=INT_MAX;
    
    for(int x=1;x<=n;x++){
        int op1 = minAttempts(x-1,e-1)+1;
        int op2 = minAttempts(n-x,e)+1;
        attempts = min(attempts,max(op1,op2));
    }
    
    return dp[n][e]=attempts;
}

int main(){
    for(int n=0;n<=50;n++){
        for(int e=0;e<=10;e++){
            dp[n][e]=-1;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int e,n; // e eggs, n floors
        cin>>e>>n;
        cout<<minAttempts(n,e)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP
// Space Optimization - can be optimised to O(floors) space

#include<bits/stdc++.h>
using namespace std;

int dp[11][51];

int preCompute(int N,int E){
    for(int e=1;e<=E;e++){
        for(int n=0;n<=N;n++){
            if(n==0||n==1) dp[e][n]=n;
            else if(e==1) dp[e][n]=n;
            else {
                int attempts=INT_MAX;
                for(int x=1;x<=n;x++){
                    int op1 = dp[e-1][x-1]+1;
                    int op2 = dp[e][n-x]+1;
                    attempts = min(attempts,max(op1,op2));
                }
                dp[e][n]=attempts;
            }
        }
    }
}

int main(){
    preCompute(50,10);
    int t;
    cin>>t;
    while(t--){
        int e,n; // e eggs, n floors
        cin>>e>>n;
        cout<<dp[e][n]<<"\n";
    }
	return 0;
}