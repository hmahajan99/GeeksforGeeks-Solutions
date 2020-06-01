// Similar to InterviewBit-Solutions/Binary Search/Sort modification/Median of Array.cpp

// Given two sorted arrays A and B of size M and N respectively and an element k. 
// The task is to find the element that would be at the k’th position of the final sorted array.
// Example:
// Input:
// 1
// 5 4 5
// 2 3 6 7 9
// 1 4 8 10
// Output:
// 6
// Explanation:
// Testcase 1: Element at 5th position after merging both arrays will be 6.

// Approach 1: Brute force, Time - O(k)
// We used a simple Merge based solution just we are not merging the array instead we are keeping track of the last element read 
// till we reach the kth element

/***************************************************************************************************************************/

// Approach 2: Like Matrix Median approach, binary search on each row and count number of elements <= mid
// Time - log(INT_MAX)*(logm+logn)

/***************************************************************************************************************************/

// Approach 3: Binary search on smaller array, Partition both such that total elements on left side is half
// Time - O(log(min(m,n)))
// NOTE: COMMON APPROACH For BINARY SEARCH on 2 SORTED ARRAYS
// Similar to InterviewBit-Solutions/Binary Search/Sort modification/Median of Array.cpp

#include<bits/stdc++.h>
using namespace std;

int findKthElementSortedArrays(int k,const vector<int> &X, const vector<int> &Y) {
    int x = X.size(), y = Y.size();
    if(x>y) return findKthElementSortedArrays(k,Y,X);
    
    if(x==0) return Y[k-1];
    
    int l=0,r=x;
    while(l<=r){
        // size(leftPartitionX)=partitionX
        int partitionX = (l+r)/2;  
        // size(leftPartitionY)=partitionY
        int partitionY = k - partitionX;

        // Corner cases
        if(partitionY>y){
            l = partitionX+1;
            continue;
        }
        if(partitionY<0){
            r = partitionX-1;
            continue;
        }

        int maxLeftX = (partitionX==0)?(INT_MIN):X[partitionX-1];
        int minRightX = (partitionX==x)?(INT_MAX):X[partitionX];

        int maxLeftY = (partitionY==0)?(INT_MIN):Y[partitionY-1];
        int minRightY = (partitionY==y)?(INT_MAX):Y[partitionY];

        if(maxLeftX<=minRightY&&maxLeftY<=minRightX){
            return max(maxLeftX,maxLeftY);
        }
        
        else if(maxLeftX>minRightY) r = partitionX-1;
        else l = partitionX+1;
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        cout<<findKthElementSortedArrays(k,a,b)<<"\n";
    }
	return 0;
}