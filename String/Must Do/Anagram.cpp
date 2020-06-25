// Given two strings a and b consisting of lowercase characters. 
// The task is to check whether two given strings are anagram of each other or not. 
// An anagram of a string is another string that contains same characters, only the order of characters can be different. 
// For example, “act” and “tac” are anagram of each other.

// Approach 1: Sorting, O(nlogn)
// Sort both strings & Compare the sorted strings

/***************************************************************************************************************************/

// Approach 2: Hashmap, O(n)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        
        if(s1.size()!=s2.size()){
            cout<<"NO\n";
            continue;
        }
        
        unordered_map<char,int> m1,m2;
        
        bool sol=true;
        for(const char& ch:s1) m1[ch]++;
        for(const char& ch:s2) m2[ch]++;
        for(const char& ch:s1){
            if(m1[ch]!=m2[ch]){
                sol = false;
                break;
            }
        }
        
        if(sol) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}