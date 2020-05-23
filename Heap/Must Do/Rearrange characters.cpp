// Given a string S with repeated characters (only lowercase). 
// The task is to rearrange characters in a string such that no two adjacent characters are same.
// For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, 
// else if no such string is possible to be made print "0" (without quotes).
// Example:
// Input:
// 3
// geeksforgeeks
// bbbabaaacd
// bbbbb
// Output:
// 1
// 1
// 0

// Approach: Heaps
// The idea is to put the highest frequency character first (a greedy approach). 
// We use a priority queue (Or Binary Max Heap) and put all characters and ordered by their frequencies (highest frequency character at root). 
// We one by one take the highest frequency character from the heap and add it to result. 
// After we add, we decrease the frequency of the character and we temporarily move this character out of priority queue so that it is not picked next time.

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> node;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<char,int> m;
        for(char ch:s) m[ch]++;
        
        priority_queue<node,vector<node>,less<node>> maxPq;
        for(auto p:m) maxPq.push({p.second,p.first});
        
        string t="";
        node prev = {-1,'\0'};
        while(!maxPq.empty()){
            node top = maxPq.top();
            maxPq.pop();
            t += top.second;
            if(prev.first>0) maxPq.push(prev);
            top.first--;
            prev = top;
        }
        
        if(t.size()==s.size()) cout<<1<<"\n";
        else cout<<0<<"\n";
        
    }

	return 0;
}