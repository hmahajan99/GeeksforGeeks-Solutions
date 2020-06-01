// The task is to complete merge() function which is used to implement Merge Sort.

/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){
    int *out = new int[r-l+1];
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(arr[i]<arr[j]) out[k++]=arr[i++];
        else out[k++]=arr[j++];
    }
    while(i<=m) out[k++]=arr[i++];
    while(j<=r) out[k++]=arr[j++];
    for(int x=l,y=0;x<=r;x++,y++) arr[x]=out[y];
    delete [] out;
}