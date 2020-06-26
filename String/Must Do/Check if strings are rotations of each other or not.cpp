// Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

// Approach

// 1. Create a temp string and store concatenation of str1 to str1 in temp.
//   temp = str1.str1
// 2. If str2 is a substring of temp then str1 and str2 are rotations of each other.

// Example: str1 = "ABACD" str2 = "CDABA" temp = str1.str1 = "ABACDABACD"
// Since str2 is a substring of temp, str1 and str2 are rotations of each other.

#include<iostream>
using namespace std;

bool areRotations(string str1, string str2) { 
    if (str1.length() != str2.length()) return false; 
    string temp = str1 + str1;  
    return (temp.find(str2) != string::npos); 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<areRotations(s1,s2)<<"\n";
    }
	return 0;
}