// Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
// 1. Each student gets one packet.
// 2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.

// Example:
// Input:
// 2
// 8
// 3 4 1 9 56 7 9 12
// 5
// 7
// 7 3 2 4 9 12 56
// 3

// Output:
// 6
// 2

// Explanation:
// Testcase 1: The minimum difference between maximum chocolates and minimum chocolates is 9-3=6

// Approach
// To minimize the difference, we must choose consecutive elements from a sorted packet.
// We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between last and first elements.

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lli long long
using namespace std;
int main(){
    FIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int m;
        cin>>m;
        sort(a,a+n);
        lli ans=LLONG_MAX;
        for(int i=m-1;i<n;i++){
            ans=min(ans,a[i]-a[i-m+1]);
        }
        cout<<ans<<"\n";
    }

	return 0;
}