// Given two arrays X and Y of positive integers, find number of pairs such that x^y > y^x where x is an element from X and y is an element from Y.

// Approach

// Sort array Y[].
// For every x in X[], find the index idx of smallest number greater than x (also called ceil of x) in Y[] using binary search or we can use the inbuilt function upper_bound() in algorithm library.
// All the numbers after idx satisfy the relation so just add (n-idx) to the count.

// Base Cases and Exceptions:
// Following are exceptions for x from X[] and y from Y[]

// 1) If x = 0, then the count of pairs for this x is 0.
// 2) If x = 1, then the count of pairs for this x is equal to count of 0s in Y[].
// 3) x smaller than y means x^y is greater than y^x.
//     x = 2, y = 3 or 4
//     x = 3, y = 2

#include<bits/stdc++.h>
using namespace std;

// Return count of pairs with x ^ Y[i] > Y[i] ^ x 
int count(int x, int Y[], int n, int NoOfY[]) { 
    // If x is 0, then there cannot be any value in Y such that x^Y[i] > Y[i]^x 
    if (x == 0) return 0; 
  
    // If x is 1, then the number of pais is equal to number of zeroes in Y[] 
    if (x == 1) return NoOfY[0]; 
  
    // Find number of elements in Y[] with values greater than x 
    int* idx = upper_bound(Y, Y + n, x); 
    int ans = (Y + n) - idx; 
  
    // If we have reached here, then x must be greater than 1, 
    // increase number of pairs for y=0 and y=1 
    ans += (NoOfY[0] + NoOfY[1]); 
  
    // Decrease number of pairs for x=2 and (y=4 or y=3) 
    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]); 
  
    // Increase number of pairs for x=3 and y=2 
    if (x == 3)  ans += NoOfY[2]; 
  
    return ans; 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int X[m],Y[n];
        for(int i=0;i<m;i++) cin>>X[i];
        int NoOfY[5] = {0};  // To store counts of 0, 1, 2, 3 and 4 in array Y
        for(int i=0;i<n;i++){
            cin>>Y[i];
            if (Y[i]<5) NoOfY[Y[i]]++; 
        } 
        sort(Y,Y+n);
        long long totalPairs = 0; 
        for(int i=0;i<m;i++) totalPairs += count(X[i], Y, n, NoOfY); 
        cout<<totalPairs<<"\n"; 
    }
	return 0;
}