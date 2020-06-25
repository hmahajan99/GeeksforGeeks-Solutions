// Given a string s, recursively remove adjacent duplicate characters from the string s. 
// The output string should not have any adjacent duplicates.

// Approach 1
// Corner Case: mississipie => mpie

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    int n = s.size();
    if(n<=1) return s;
    string s1;
    if(s[0]!=s[1]){
        return s[0] + removeDuplicates(s.substr(1));    
    }else{
        int i=0;
        while(i<n&&s[i]==s[0]) i++;
        return removeDuplicates(s.substr(i));
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string s1 = removeDuplicates(s);
        while(s.size()!=s1.size()){
            s = s1;
            s1 = removeDuplicates(s);
        }
        cout<<s1<<"\n";
    }
	return 0;
}
