// Given two strings s1 and s2. Modify string s1 such that all the common characters of s1 and s2 is to be removed 
// and the uncommon characters of s1 and s2 is to be concatenated.

// Note: If no modification is possible print -1.

#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        unordered_set<char> st1,st2;
        for(char& ch:s1) st1.insert(ch);
        for(char& ch:s2) st2.insert(ch);
        string ans="";
        for(char& ch:s1) if(!st2.count(ch)) ans+=ch;
        for(char& ch:s2) if(!st1.count(ch)) ans+=ch;
        if(!ans.size()) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
	return 0;
}

// Alternative
// An idea is to use hash map where key is character and value is number of strings in which character is present. 
// If a character is present in one string, then count is 1, else if character is present in both strings, count is 2.