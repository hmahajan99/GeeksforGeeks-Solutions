// You are required to complete the 3 methods insertKey() which take one argument the value to be inserted, 
// deleteKey() which takes one argument the position from where the element is to be deleted and 
// extractMin() which returns the minimum element in the heap.

// Expected Time Complexity: O(Q*Log(size of Heap) ).
// Expected Auxiliary Space: O(1).

// Operations on Min Heap:
// 1) getMini(): It returns the root element of Min Heap. Time Complexity of this operation is O(1).
// 2) extractMin(): Removes the minimum element from MinHeap. Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.
// 3) decreaseKey(): Decreases value of key. The time complexity of this operation is O(Logn). If the decreases key value of a node is greater than the parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.
// 4) insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.
// 5) delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with minum infinite by calling decreaseKey(). After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove the key.

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/

// You need to write code for below three functions

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() {
    if(heap_size==0) return -1;

    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
}

// This function deletes key at index i. It first reduced value to minus infinite, then calls extractMin()     
void MinHeap::deleteKey(int i) {
    if(i>=heap_size) return;

    decreaseKey(i, INT_MIN); 
    extractMin();     
}

// Inserts a new key 'k' 
void MinHeap::insertKey(int k) {
    if(heap_size == capacity) return;
    
    harr[heap_size] = k;
    int i = heap_size;
    heap_size++;
    while(i>0 && harr[parent(i)] > harr[i]){
        swap(harr[i],harr[parent(i)]);
        i = parent(i);
    }
}

// Decrease Key operation, helps in deleting key from heap
// Decreases value of key at index 'i' to new_val.  It is assumed that new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in above codes. Please do not delete this code if you are not writing your own MinHeapify */
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}