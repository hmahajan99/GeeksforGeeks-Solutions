// Given an array of positive integers. The task is to find inversion count of array.

// Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. 
// If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Approach 1: Brute Force, O(n^2)

/***************************************************************************************************************************/

// Approach 2: Enhanced Merge Sort, O(nlogn)

// To get a number of inversions, that needs to be added a number of inversions in the left subarray, right subarray and merge().
// How to get number of inversions in merge()?
// In merge process, let i is used for indexing left sub-array and j for right sub-array. 
// At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
// Because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

#include<iostream>
#define lli long long
using namespace std;

lli merge(int arr[], int l, int m, int r){
    int *out = new int[r-l+1];
    int i=l,j=m+1,k=0;
    lli inversions=0;
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j]) out[k++]=arr[i++];
        else{
            inversions+=m-i+1;
            out[k++]=arr[j++];    
        } 
    }
    while(i<=m) out[k++]=arr[i++];
    while(j<=r) out[k++]=arr[j++];
    for(int x=l,y=0;x<=r;x++,y++) arr[x]=out[y];
    delete [] out;
    return inversions;
}

lli countInversions(int arr[], int l, int r) {
    lli inversions=0;
    if (l < r)   {
        int m = l+(r-l)/2;
        inversions+=countInversions(arr, l, m);
        inversions+=countInversions(arr, m+1, r);
        inversions+=merge(arr, l, m, r);
    }
    return inversions;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<countInversions(a,0,n-1)<<"\n";
    }
	return 0;
}