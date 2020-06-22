// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// Approach: Sliding Window & Hashmap
// Time complexity O(n) 
// Space Compelxity O(n)

vector <int> countDistinct (int A[], int n, int k) {
    vector<int> ans;
    unordered_map<int,int> count;
    for(int i=0;i<n;i++){
        count[A[i]]++;
        if(i>=k-1){
            ans.push_back(count.size());
            count[A[i-k+1]]--;
            if(count[A[i-k+1]]==0) count.erase(A[i-k+1]);
        }
    }
    return ans;
}