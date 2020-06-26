// Given a set of n nuts of different sizes and n bolts of different sizes. 
// There is a one-one mapping between nuts and bolts. 
// Match nuts and bolts efficiently.
// Constraint: Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
// It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

// Other way of asking this problem is, given a box with locks and keys where one lock can be opened by one key in the box. We need to match the pair.

// Example:
// Input:
// 2
// 5
// @ % $ # ^
// % @ # $ ^
// 9
// ^ & % @ # * $ ~ !
// ~ # @ % & * $ ^ ! 

// Output:
// # $ % @ ^
// # $ % @ ^
// ! # $ % & * @ ^ ~
// ! # $ % & * @ ^ ~

// Approach 1: Brute Force
// Start with the first bolt and compare it with each nut until we find a match. 
// In the worst case we require n comparisons. Doing this for all bolts gives us O(n^2) complexity.

/***************************************************************************************************************************/

// Approach 2: Quick sort way

// This algorithm first performs a partition by picking last element of bolts array as pivot, rearrange the array of nuts 
// and returns the partition index ‘i’ such that all nuts smaller than nuts[i] are on the left side 
// and all nuts greater than nuts[i] are on the right side. Next using the nuts[i] we can partition the array of bolts. 
// Partitioning operations can easily be implemented in O(n). This operation also makes nuts and bolts array nicely partitioned. 
// Now we apply this partitioning recursively on the left and right sub-array of nuts and bolts.
// As we apply partitioning on nuts and bolts both so the total time complexity will be Θ(2*nlogn) = Θ(nlogn) on average.
// Here for the sake of simplicity we have chosen last element always as pivot. We can do randomized quick sort too.

#include<iostream>
using namespace std;

int partition (char arr[], int low, int high, char pivot){
    int countSmaller = 0;
    int prevPivotIndex;
    for(int i=low;i<=high;i++){
        if(arr[i]==pivot) prevPivotIndex = i;
        if(arr[i]<pivot) countSmaller++;
    }
    int pivotIndex = low + countSmaller;
    swap(arr[prevPivotIndex],arr[pivotIndex]);
    int i=low,j=high;
    while(i<pivotIndex&&j>pivotIndex){
        if(arr[i]<pivot) i++;
        else if(arr[j]>=pivot) j--;
        else swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}

// Method which works just like quick sort 
void matchPairs(int low, int high, char nuts[], char bolts[]) {
    if (low < high)     {
        // Choose last character of bolts array for nuts partition. 
        int pivot = partition(nuts, low, high, bolts[high]); 
        // Now using the partition of nuts choose that for bolts partition. 
        partition(bolts, low, high, nuts[pivot]);         

        matchPairs(low, pivot-1, nuts, bolts); 
        matchPairs(pivot+1, high, nuts, bolts);    
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char nuts[n],bolts[n];
        for(int i=0;i<n;i++) cin>>nuts[i];
        for(int i=0;i<n;i++) cin>>bolts[i];
        matchPairs(0,n-1,nuts,bolts);
        for(int i=0;i<n;i++) cout<<nuts[i]<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++) cout<<bolts[i]<<" ";
        cout<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 3: Hashmap
// Travese the nuts array and create a hashmap
// Traverse the bolts array and search for it in hashmap.
// If it is found in the hashmap of nuts than this means bolts exist for that nut.
