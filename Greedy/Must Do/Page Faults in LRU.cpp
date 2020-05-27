// In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when the new page comes in. 
// Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page. 
// Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.
// Input:
// The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.
// Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at the start.
// Output:
// Output the number of page faults.

// Example:
// Input:
// 2
// 9
// 5 0 1 3 2 4 1 0 5
// 4
// 8
// 3 1 0 2 5 4 1 2
// 4
// Output:
// 8
// 7

// Explanation:
// Testcase 1:
// memory allocated with 4 pages 5, 0, 1, 3: page fault = 4
// page number 2 is required, replaces LRU 5: page fault = 4+1 = 5
// page number 4 is required, replaces LRU 0: page fault = 5 + 1 = 6
// page number 1 is required which is already present: page fault = 6 + 0 = 6
// page number 0 is required which replaces LRU 3: page fault = 6 + 1 = 7
// page number 5 is required which replaces LRU 2: page fault = 7 + 1  =8.

// Approach: Doubly Linked List + Hashing
// IMP NOTE: Doubly Linked List + Hashing used in many questions (similar to indexing concept)

// In Least Recently Used (LRU) algorithm is a Greedy algorithm where the page to be replaced is least recently used. 
// The idea is based on locality of reference.

#include<bits/stdc++.h>
using namespace std;

typedef list<int>::iterator li;
typedef unordered_map<int,li> hili;

class LRUCache {
    list<int> used; // DLL, stores keys ordered by access time (MRU at front, LRU at back)
    hili cache; // key -> (iterator i.e position int the list, like Node*)
    int cacheCapacity;
    
public:
    int pageFaults;

    LRUCache(int capacity) {
        cacheCapacity=capacity;
        pageFaults=0;
    }

    void add(int key) {
        if(cache.count(key)>0){
            // Erase key if already present
            used.erase(cache[key]); // list.erase(iterator)
            cache.erase(key);
        }else{
            pageFaults++;
        }
        
        // Check if cache full
        if(cache.size()==cacheCapacity){
            cache.erase(used.back());
            used.pop_back();
        }
            
        // Insert Key
        used.push_front(key);
        cache[key] = used.begin(); 
    }

    
};



int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int capacity;
        cin>>capacity;
        LRUCache l(capacity);
        for(int i=0;i<n;i++) l.add(arr[i]);
        cout<<l.pageFaults<<"\n";
    }

	return 0;
}