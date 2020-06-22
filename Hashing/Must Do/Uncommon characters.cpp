// Find and print the uncommon characters of the two given strings S1 and S2. 
// Here uncommon character means that either the character is present in one string or it is present in other string but not in both. 
// The strings contains only lowercase characters and can contain duplicates.

// Approach: Hashing

#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        unordered_set<char> set1;
        unordered_set<char> set2;
        for(char ch:s1) set1.insert(ch);
        for(char ch:s2) set2.insert(ch);
        
        string ans="";
        for(char ch='a';ch<='z';ch++){
            bool b1 = (set1.count(ch)&&!set2.count(ch));
            bool b2 = (!set1.count(ch)&&set2.count(ch));
            if(b1||b2) ans+=ch;
        }
        cout<<ans<<"\n";
        
    }

	return 0;
}