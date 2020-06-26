// Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” 
// and converts them into a short 6 character URL. It is given that URLs are stored in database 
// and every URL has an associated integer id.  So your program should take an integer id and generate a 6 character long URL. 

// A URL character can be one of the following

// A lower case alphabet [‘a’ to ‘z’], total 26 characters
// An upper case alphabet [‘A’ to ‘Z’], total 26 characters
// A digit [‘0′ to ‘9’], total 10 characters
// There are total 26 + 26 + 10 = 62 possible characters.

// So the task is to convert an integer (database id) to a base 62 number where 
// digits of 62 base are "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

// Example:
// Input:
// 1
// 12345

// Output:
// dnh
// 12345

#include<bits/stdc++.h>
using namespace std;

string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string getUrl(int n){
    string url="";
    while(n){
        url+=chars[n%62];
        n/=62;
    }
    reverse(url.begin(),url.end());
    return url;
}

int getId(string url){
    int id=0;
    for (int i=0; i < url.length(); i++) { 
        if ('a' <= url[i] && url[i] <= 'z') 
          id = id*62 + url[i] - 'a'; 
        if ('A' <= url[i] && url[i] <= 'Z') 
          id = id*62 + url[i] - 'A' + 26; 
        if ('0' <= url[i] && url[i] <= '9') 
          id = id*62 + url[i] - '0' + 52; 
    } 
    return id;     
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string url = getUrl(n);
        cout<<url<<"\n";
        cout<<getId(url)<<"\n";
    }
	return 0;
}