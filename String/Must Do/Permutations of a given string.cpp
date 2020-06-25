// Given a string S. The task is to print all permutations of a given string in lexicographically increasing order.

// Approach 1: Using STL next_permutation

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        do {
            cout<<s<<" ";
        }while(next_permutation(s.begin(),s.end()));
        cout<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Backtracking

#include<bits/stdc++.h>
using namespace std;

set<string> st;

void getPermutations(int i,string &s){
    if(i==s.size()){
        st.insert(s);
        return;
    }
    
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        getPermutations(i+1,s);
        swap(s[i],s[j]);
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        st.clear();
        getPermutations(0,s);
        for(string p:st) cout<<p<<" ";
        cout<<"\n";
    }
	return 0;
}
