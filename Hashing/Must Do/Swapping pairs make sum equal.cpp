// Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists such that 
// swapping the elements of the pair will make the sum of two arrays equal.

// We are looking for two values, a and b, such that: 
// sumA - a + b = sumB - b + a
//     2a - 2b  = sumA - sumB
//       a - b  = (sumA - sumB) / 2

// Approach 1: Sort the arrays and use 2 pointer technique for finding 2 no's with required difference
// Time Complexity :-
// If arrays are sorted : O(n + m)
// If arrays aren’t sorted : O(nlog(n) + mlog(m))

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i]; 
        int b[m];
        for(int i=0;i<m;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+m);
        int sum1 = accumulate(a,a+n,0);
        int sum2 = accumulate(b,b+m,0);
        int reqDiff = (sum1-sum2)/2;
        int i=0,j=0;
        bool sol = false;
        while(i<n&&j<m){
            int diff = a[i]-b[j]; 
            if(diff==reqDiff){
                sol = true;
                break;
            }else if(diff<reqDiff){
                if(a[i]<b[j]) j++;
                else i++;
            }else{
                if(a[i]<b[j]) i++;
                else j++;
            } 
            
        }
        if(sol) cout<<1<<"\n";
        else cout<<-1<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using Hashing
// O(m+n) time and O(m) auxiliary space
// Make a hashset for small array(here array1).
// Calculate diff as (sum1-sum2)/2.
// Run a loop for array2 and check if hashset contains (array2[i]+diff)
