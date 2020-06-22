// You are given an array of integers. You need to print the total count of sub-arrays having their sum equal to 0

// Example:
// Input:
// 2
// 6
// 0 0 5 5 0 0
// 10
// 6  -1 -3 4 -2 2 4 6 -12 -7
// Output:
// 6
// 4

// Explanation:
// IMP !!!!=> Testcase 1: There are 6 subarrays present whose sum is zero. The starting and ending indices are:
// (0,0) (1,1) (0,1) (4,4) (5,5) (4,5)

// Approach 1: Brute force
// A simple solution is to consider all subarrays one by one and check if sum of every subarray is equal to 0 or not. 
// The complexity of this solution would be O(n^2).

/***************************************************************************************************************************/

// Approach 2: Use Hashing & Prefix sum
// Time Complexity: O(N)
// Auxiliary Space: O(N)

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        unordered_map<int,int> prefixSum; // frequency of prefixSum
        prefixSum[0]=1; // IMP, If current sum is 0, we found a subarray starting from index 0 and ending at index current index
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            if(prefixSum.count(sum)){
                ans+=prefixSum[sum];
            }
            prefixSum[sum]++;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
