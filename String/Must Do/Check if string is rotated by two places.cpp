// Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        
        int n = s2.size();
        bool sol;
        
        if(s1.size()!=n) sol = false;
        else if(n<=2) sol = s1 == s2;
        else {
            string r1 = s2.substr(2) + s2.substr(0,2);
            string r2 = s2.substr(n-2) + s2.substr(0,n-2);  
            sol = (s1 == r1) || (s1 == r2);            
        }
        cout<<sol<<"\n";

    }
	return 0;
}