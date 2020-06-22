// Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. 
// Task is to check whether arr2[] is a subset of arr1[] or not. 
// Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

// Approach 1: Brute force, O(m*n)
// Use two loops: The outer loop picks all the elements of arr2[] one by one.

/***************************************************************************************************************************/

// Approach 2: Sorting and Binary Search, O(mLogm + nLogm)
// Sort arr1[] which takes O(mLogm)
// For each element of arr2[], do binary search for it in sorted arr1[].

/***************************************************************************************************************************/

// Approach 3: Use Hashing

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int a1[m],a2[n];
        unordered_set<int> s;
        for(int i=0;i<m;i++){
            cin>>a1[i];
            s.insert(a1[i]);
        } 
        bool isSubset = true;
        for(int i=0;i<n;i++){
            cin>>a2[i];    
            if(!s.count(a2[i])) isSubset = false;
        } 
        
        if(isSubset) cout<<"Yes\n";
        else cout<<"No\n";

    }
	return 0;
}