// Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. 
// The converted array should be in form a < b > c < d > e < f. 
// The relative order of elements is same in the output i.e you have to iterate on the original array only.

// Example:
// Input:
// 2
// 7
// 4 3 7 8 6 2 1
// 4
// 1 4 3 2
// Output:
// 3 7 4 8 2 6 1
// 1 4 2 3

// Approach 1: Sorting
// A Simple Solution is to first sort the array. After sorting, exclude the first element, swap the remaining elements in pairs. 
// (i.e. keep arr[0] as it is, swap arr[1] and arr[2], swap arr[3] and arr[4], and so on). 
// Time complexity is O(nlogn) since we need to sort the array first.


/***************************************************************************************************************************/

// Approach 2: O(n) solution

// The idea is to use a modified one pass of bubble sort.

// Maintain a flag for representing which order(i.e. < or >) currently we need.
// If the current two elements are not in that order then swap those elements otherwise not.
// Let us see the main logic using three consecutive elements A, B, C.

// Suppose we are processing B and C currently and the current relation is ‘<', but we have B > C. 
// Since current relation is ‘<' previous relation must be '>‘ i.e., A must be greater than B. 
// So, the relation is A > B and B > C. We can deduce A > C. So if we swap B and C then the relation is A > C and C < B. 
// Finally we get the desired order A C B

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        for(int i=0;i<n-1;i++){
            if((i&1)==0){ // even index
                if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            }else{
                if(a[i]<a[i+1]) swap(a[i],a[i+1]);
            }            
        }

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";

    }
	return 0;
}