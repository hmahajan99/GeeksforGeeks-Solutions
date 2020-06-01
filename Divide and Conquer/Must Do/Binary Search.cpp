// Given a sorted array A[](0 based index) and a key "k"  you need to complete the function bin_search to  determine 
// the position of the key if the key is present in the array. 
// If the key is not  present then you have to return -1.

// Approach 1: Iterative, O(logn)

/*You need to complete this function */
int bin_search(int A[], int left, int right, int k){
    while(left<=right){
        int mid = (left+right)/2;
        if(A[mid]==k) return mid;
        else if(A[mid]>k) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

/***************************************************************************************************************************/

// Approach 2: Recursive, O(logn)

/*You need to complete this function */
int bin_search(int A[], int left, int right, int k){
    if(left>right) return -1;
    int mid = (left+right)/2;
    if(A[mid]==k) return mid;
    else if(A[mid]>k) return bin_search(A,left,mid-1,k);
    else return bin_search(A,mid+1,right,k);
}