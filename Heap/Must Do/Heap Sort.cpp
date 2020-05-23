// Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.
// Sorted array in ascending order.

// Heap sort is an in-place algorithm.
// Its typical implementation is not stable
// Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).


/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[], n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
    int parentIndex = i;
    int LCI=2*parentIndex+1, RCI=2*parentIndex+2;
    while(LCI<n){
        int maxIndex = parentIndex;
        if(arr[LCI]>arr[maxIndex]) maxIndex = LCI;
        if(RCI<n&&arr[RCI]>arr[maxIndex]) maxIndex = RCI;
        
        if(maxIndex==parentIndex) break;
        swap(arr[maxIndex],arr[parentIndex]);
        parentIndex = maxIndex;
        LCI=2*parentIndex+1; 
        RCI=2*parentIndex+2;
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex]>arr[parentIndex]){
                swap(arr[childIndex],arr[parentIndex]);
                childIndex = parentIndex;
            } 
            else break;
        }
    }
}
