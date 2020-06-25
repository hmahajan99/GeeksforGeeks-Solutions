// Given a string S, find length of the longest substring with all distinct characters.  
// For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

// Approach 1: Brute force, O(n^2)
// We can consider all substrings one by one and check for each substring whether it contains all unique characters or not using hashmap. 

/***************************************************************************************************************************/

// Approach 2: Sliding Window / 2 Pointer + Hashmap, O(n)

#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_set<char> st;
        int start=0,ans=0;
        for(int end=0;end<s.size();end++){
            if(st.count(s[end])){
                while(s[start]!=s[end]){
                    st.erase(s[start]);
                    start++;    
                } 
                st.erase(s[start]);
                start++;    
            }
            st.insert(s[end]);
            ans=max(ans,end-start+1);
        }
        cout<<ans<<"\n";
    }

	return 0;
}
