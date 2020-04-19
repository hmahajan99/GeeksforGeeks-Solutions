// Given an input stream of N characters consisting only of lower case alphabets. 
// The task is to find the first non repeating character, each time a character is inserted to the stream. 
// If no non repeating element is found print -1.

// Example:
// Input:
// 2
// 4
// a a b c
// 3
// a a c
// Output:
// a -1 b b
// a -1 c

// Approach 1: DLL + Hashmap (like INDEXING)
// IMP NOTE: Doubly Linked List + Hashing used in many questions (similar to indexing concept)

// The idea is to use a DLL (Doubly Linked List) to efficiently get the first non-repeating character from a stream. 
// The DLL contains all non-repeating characters in order, i.e., the tail of DLL contains first non-repeating character, the second last node contains the second non-repeating and so on.

// Note that appending a new node to DLL is O(1) operation. 
// Removing a node from DLL is also O(1). 
// So both operations, addition of new character and finding first non-repeating character take O(1) time.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        list<char> dll; // tail of DLL contains first non-repeating character
        unordered_map<char,list<char>::iterator> index;
        unordered_map<char,int> freq;
        for(int i=1;i<=n;i++){
            char x;
            cin>>x;
            if(!freq.count(x)){
                dll.push_front(x);
                index[x]=dll.begin();
            }else if(freq[x]==1){
                dll.erase(index[x]);
                index.erase(x);
            }
            freq[x]++;
            
            if(dll.empty()) cout<<-1<<" ";
            else cout<<dll.back()<<" ";
        }
        cout<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Queue based approach
// Store each character in queue and increase its frequency in the hash array.
// For every character of stream, we check front of the queue.
// If the frequency of character at the front of queue is one, then that will be the first non repeating character.
// Else if frequency is more than 1, then we pop that element.
// If queue became empty that means there are no non repeating character so we will print -1.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<char> q;
        unordered_map<char,int> freq;
        for(int i=1;i<=n;i++){
            char x;
            cin>>x;
            freq[x]++;
            q.push(x);
            while(!q.empty()&&freq[q.front()]>1){
                q.pop();
            }
            if(q.empty()) cout<<-1<<" ";
            else cout<<q.front()<<" ";
        }
        cout<<"\n";
    }
	return 0;
}