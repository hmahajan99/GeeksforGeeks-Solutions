// Given a string, the task is to remove duplicates from it. 
// Expected time complexity O(n) where n is length of input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

// Note: that original order of characters must be kept same.

// Example:
// Input:
// 2
// geeksforgeeks
// geeks for geeks

// Output:
// geksfor
// geks for

// Approach: In place removal of duplicate characters
// NOTE: IMP !!!!=> USING cin.ignore()

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore(); // IMP!!!=> used to ignore the new line character
    while(t--){
        string s1;
        getline(cin,s1); // Use getline function to input the string as it can be multiword string
        unordered_set<char> st;
        for(int i=0;i<s1.size();i++){
            st.insert(s1[i]);
        }
        int j=0;
        for(int i=0;i<s1.size();i++){
            if(st.count(s1[i])){
                s1[j] = s1[i];
                j++;
                st.erase(s1[i]);
            } 
        }
        s1.erase(s1.begin()+j,s1.end());
        cout<<s1<<"\n";
    }
	return 0;
}