// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
// Example:
// Input:
// K = 3
// arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation:Above test case has 3 sorted
// arrays of size 3, 3, 3
// arr[][] = [[1, 2, 3],[4, 5, 6], 
// [7, 8, 9]]
// The merged list will be 
// [1, 2, 3, 4, 5, 6, 7, 8, 9].

// Approach: Heaps
// The idea is to use Min Heap. This MinHeap based solution has the same time complexity which is O(NKlogK).
// The process must start with creating a MinHeap and inserting the first element of all the k arrays to the heap.
// Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element. 
// To get the result the step must continue until there is no element in the MinHeap or the arrays left.

int *mergeKArrays(int arr[][N], int k)
{
    int *ans = new int[k*k];
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    
    int maxn[k];
    for(int i=0;i<k;i++)
    {
        q.push({arr[i][0],i});
        maxn[i]=1;
    }
    int i=0;    
    while(!q.empty())
    {
        pair<int, int> val = q.top();
        ans[i]=val.first;i++;
        q.pop();
        if(maxn[val.second]<k)
        {
            q.push({arr[val.second][maxn[val.second]],val.second});
            maxn[val.second]++;
        }
    }
    return ans;
}
