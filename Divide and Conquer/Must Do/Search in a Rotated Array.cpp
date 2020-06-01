// Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
// The task is to find the index of the given element K in the array A.
// Input : arr[] = {30, 40, 50, 10, 20}
//         key = 10   
// Output : Found at index 3

// NOTE: Assume that all elements in array are distinct

// Approach: Binary Search, O(logn)
// ALTERNATIVE: Could write RECURSIVE solution for Binary Search as well

// 1) Find middle point mid = (l + h)/2
// 2) If key is present at middle point, return mid.
// 3) Else If arr[l..mid] is sorted
//     a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
//     b) Else recur for arr[mid+1..h]
// 4) Else (arr[mid+1..h] must be sorted)
//     a) If key to be searched lies in range from arr[mid+1] to arr[h], recur for arr[mid+1..h].
//     b) Else recur for arr[l..mid] 

#include<iostream>
using namespace std;

int search(int k, int a[], int n){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(a[mid]==k) return mid;

        if(a[s]<=a[mid]){        // Left part is sorted
            if(a[s]<=k&&k<a[mid]) e=mid-1;
            else s=mid+1;
        }else {                  // Right part is sorted
            if(a[mid]<k&&k<=a[e]) s=mid+1;
            else e=mid-1;
        } 
    }
    
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int k;
        cin>>k;
        cout<<search(k,a,n)<<"\n";
    }
	return 0;
}