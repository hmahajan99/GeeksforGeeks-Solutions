// Given a sorted array A, size N, of integers; every element appears twice except for one. 
// Find that element that appears once in array.

// Approach 1: Brute Force / XOR all elements
// Time - O(n) 

/***************************************************************************************************************************/

// Approach 2: Binary Search, O(logN) time

// All elements before the required have first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …). 
// And all elements after the required element have first occurrence at odd index and next occurrence at even index.
// 1) Find the middle index, say ‘mid’.
// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are same, then the required element after ‘mid’ else before mid.
// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are same, then the required element after ‘mid’ else before mid.

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
	    int s=0,e=n-1;
	    int ans;
	    while(s<=e){
	        int mid = (s+e)/2;

          bool b1 = mid>0 && a[mid]==a[mid-1];
          bool b2 = mid<n-1 && a[mid]==a[mid+1];
          if(!b1&&!b2){
            ans = a[mid];
            break;
          }else if(mid%2==0){
            if(mid<n-1&&a[mid]==a[mid+1]) s = mid+1;
            else e = mid-1;
	        }else{
            if(mid<n-1&&a[mid]==a[mid+1]) e = mid-1;
            else s = mid+1;
	        }
	    }
	    
	    cout<<ans<<"\n";
	}
	return 0;
}