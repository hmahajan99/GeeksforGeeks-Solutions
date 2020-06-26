// Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

// Approach 1: HashMap and Two-string method traversals
// Traverse the string again and the first character which we find has a frequency as 1 is the answer

/***************************************************************************************************************************/

// Approach 2: Traversing the string only once
// The above approach takes O(n) time, but in practice, it can be improved. 
// But the second part about running through the string again just to find the first non-repeater is not a good practice.
// In real situations, the string is expected to be much larger than your alphabet. 
// Take DNA sequences, for example, they could be millions of letters long with an alphabet of just 4 letters. 
// What happens if the non-repeater is at the end of the string? Then we would have to scan for a long time (again).

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char,pair<int,int>> m;
        for(int i=0;i<n;i++){
            if(!m.count(s[i])){
                m[s[i]] = {1,i};
            }else{
                m[s[i]].first++;
            }
        }
        
        char ch;
        int i = INT_MAX;
        for(auto& p:m){
            if(p.second.first==1&&p.second.second<i){
                ch = p.first;
                i = p.second.second;
            }
        }
        if(i==INT_MAX) cout<<-1<<"\n";
        else cout<<ch<<"\n";
        
    }
	return 0;
}