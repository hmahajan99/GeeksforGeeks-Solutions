// Given a string of both uppercase and lowercase alphabets, the task is to 
// print the string with alternate occurrences of any character dropped(including space and consider upper and lowercase as same).

// Example:
// Input:
// 2
// It is a long day dear.
// Geeks for geeks
// Output:
// It sa longdy ear.
// Geks fore

// Approach
// NOTE: IMP !!!!=> USING cin.ignore()

#include<iostream>
#include<cctype>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore(); // IMP!!!=> used to ignore the new line character
    while(t--){
        string s;
        getline(cin,s); // Use getline function to input the string as it can be multiword string
        unordered_set<char> st;
        string ans="";
        for(const char& ch:s){
            if(!st.count(tolower(ch))){
                ans+=ch;
                st.insert(tolower(ch));
            }else{
                st.erase(tolower(ch));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
