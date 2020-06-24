// Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.
// For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray 
// from the left if sum equals to subarray, else print -1.

// Approach 1: Brute Force
// A simple solution is to consider all subarrays one by one and check the sum of every subarray.
// Time Complexity: O(n^2) 
// Space Complexity: O(1)

/***************************************************************************************************************************/

// Approach 2: Sliding window, Works only for Non negative Numbers
// Idea is to use a similar approach to a sliding window. 
// Start with an empty subarray, add elements to the subarray until the sum is less than x. 
// If the sum is greater than x, remove elements from the start of the current subarray.

#include<iostream>
#define lli long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        lli n,reqSum;
        cin>>n>>reqSum;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        if(reqSum<0){
            cout<<"-1\n";
            continue;
        }
        
        bool sol = false;
        int start=0,end=0,sum=0;
        // Current window holds elements [s,e) 0 indexed
        while(end<n){
            if(start==end||sum<reqSum) sum+=a[end++];
            else sum-=a[start++];

            if(sum==reqSum){
                cout<<start+1<<" "<<end<<"\n"; // Answer is 1 indexed
                sol = true;
                break;
            }
        }
        
        while(sum>reqSum&&start<n){
            sum-=a[start++];
            if(sum==reqSum){
                cout<<start+1<<" "<<end<<"\n"; // Answer is 1 indexed
                sol = true;
                break;
            }
        }

        if(!sol) cout<<-1<<"\n";

    }

	return 0;
}

// Alternative, Nested loop (Inner loop for moving start)

#include<iostream>
#define lli long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        lli n,reqSum;
        cin>>n>>reqSum;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        if(reqSum<0){
            cout<<"-1\n";
            continue;
        }

        bool sol=false;        
        int start=0,sum=0;
        for(int end=0;end<n;end++){
            sum+=a[end];
            while(start<=end&&sum>reqSum) sum-=a[start++];
            if(sum==reqSum){
                cout<<start+1<<" "<<end+1<<"\n"; // Answer is 1 indexed
                sol=true;
                break;
            }
        }

        if(!sol) cout<<-1<<"\n";

    }

	return 0;
}

/***************************************************************************************************************************/

// Approach 3: Using Hashmap, Works also for negative Numbers
// Create a Hashmap (hm) to store key value pair, i.e, key = prefix sum and value = its index and a variable to store the current sum (sum = 0) and the sum of subarray as s
// Traverse through the array from start to end. For every element update the sum, i.e sum = sum + array[i]
// If sum is equal to s then print that the subarray with given sum is from 0 to i [CORNER CASE]
// If there is any key in the HashMap which is equal to sum – s then print that the subarray with given sum is from hm[sum – s] to i
// Put the sum and index in the hashmap as key-value pair.

#include<bits/stdc++.h>
#define lli long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){


        lli n,reqSum;
        cin>>n>>reqSum;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        unordered_map<int,int> prefixSum; // index of prefixSum
        prefixSum[0]=-1; // IMP, If current sum is 0, we found a subarray starting from index 0 and ending at index current index
        int sum=0;
        bool sol=false;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(prefixSum.count(sum-reqSum)){
                cout<<prefixSum[sum-reqSum]+2<<" "<<i+1<<"\n";
                sol=true;
                break;
            }
            if(!prefixSum.count(sum)){
                prefixSum[sum]=i;
            }
        }
 
        if(!sol) cout<<-1<<"\n";

    }

	return 0;
}

/***************************************************************************************************************************/

// Approach 4: Constant space, Works also for negative Numbers

// The idea is to modify the array to contain only positive elements:

// Find the smallest negative element in the array and increment every value in the array by the absolute value of the smallest negative element found.
// We may notice that after doing the above modification, the sum of every subarray will also increase by:
// (number of elements in the subarray) * (absolute value of min element)

// After, doing the above modification in the input array, the task reduces to find if there is any subarray in the given array of only positive numbers with the new target sum. 
// This can be done using the sliding window technique in O(N) time and constant space.

// Every time while adding elements to the window, increment the target sum by the absolute value of the minimum element 
// and similarily while removing elements from the current window, decrement the target sum by the absolute value of the minimum element so that for every subarray of length say K, 
// the updated target sum will be: targetSum = sum + K*abs(minimum element)
