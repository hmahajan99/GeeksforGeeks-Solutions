// Given an array arr[] of positive integers. 
// Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
// the consecutive numbers can be in any order.

// Example:
// Input:
// 2
// 7
// 2 6 1 9 4 5 3
// 7
// 1 9 3 10 4 20 2

// Output:
// 6
// 4

// Approach 1: Sorting, O(nlogn)
// The idea is to first sort the array and find the longest subarray with consecutive elements.

/***************************************************************************************************************************/

// Approach 2: Using Hashing, O(n)
// Idea is to check all the possible starts of consecutive subsequences

// Create an empty hash. Insert all array elements to hash.
// Do following for every element arr[i]
// Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
// If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
// If the count is more than the previous longest subsequence found, then update this.

#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            cin>>a[i];  
            s.insert(a[i]);
        } 
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(!s.count(a[i]-1)){
                int len=1,temp=a[i]+1;
                while(s.count(temp)){
                    len++;
                    temp++;
                }
                ans=max(ans,len);
            }
        } 
        cout<<ans<<"\n";
        
    }
	return 0;
}