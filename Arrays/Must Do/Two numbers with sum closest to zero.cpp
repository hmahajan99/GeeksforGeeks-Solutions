// Given an integer array A of N elements. You need to find the sum of two elements such that sum is closest to zero.

// Approach: 2 Pointer
// Time - O(nlogn)

// Sort all the elements of the input array.
// Initialize l as 0 and r as n-1.
// sum = a[l] + a[r]
// If sum is -ve, then l++
// If sum is +ve, then r–

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int l=0,r=n-1;
        int ans = INT_MAX;
        while(l<r){
            int sum = a[l] + a[r];
            if(abs(sum)<abs(ans)) ans = sum;
            if(sum<0) l++;
            else r--;
        }
        cout<<ans<<"\n";
    }
	return 0;
}