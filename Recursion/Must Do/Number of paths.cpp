// The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

// Approach 1: Brute Force, recursion

#include<iostream>
using namespace std;

int numWays(int i,int j,int m,int n){
    if(i<1||j<1||i>m||j>n) return 0;
    if(i==m&&j==n) return 1;
    return numWays(i+1,j,m,n) + numWays(i,j+1,m,n);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<numWays(1,1,m,n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: DP
// Can dp Space Optimization of DP solution, we can reduce the space by O(n) where n is column size.
// See InterviewBit-Solutions/Dynamic Programming/Matrix dp/Unique Paths in a Grid.cpp

/***************************************************************************************************************************/

// Approach 3: Using combinatorics
// We have to calculate m+n-2 C n-1 here which will be (m+n-2)! / (n-1)! (m-1)!
// See InterviewBit-Solutions/Math/Combinatorics/Grid Unique Paths.cpp
