// Given an array of integers. Complete the partition() function used for the implementation of Quick Sort.
// Your task is to complete the function partition() which takes the array arr[] and the range of indices 
// to be considered [low, high] and partitions the array in the given range considering the last element as the pivot such that, 
// all the elements less than(or equal to) the pivot lie before the elements greater than it. 

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int countSmaller = 0;
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot) countSmaller++;
    }
    int pivotIndex = low + countSmaller;
    swap(arr[high],arr[pivotIndex]);
    int i=low,j=high;
    while(i<pivotIndex&&j>pivotIndex){
        if(arr[i]<=pivot) i++;
        else if(arr[j]>pivot) j--;
        else swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}
