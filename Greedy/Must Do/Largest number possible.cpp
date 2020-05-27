// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.
// Print the largest number that is possible.If their is no such number, then print -1 
// Input:
// 2
// 2 9
// 3 20
// Output: 
// 90
// 992 

// Approach: Greedy
// TRICKY/CORNER CASE => When sum = 0

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        
        // CORNER CASE
        // If sum of digits is 0, then a nuber is possible only if number of digits is 1 
        if(s==0){
            if(n==1) cout<<0<<"\n";
            else cout<<-1<<"\n";
            continue;
        } 
        
        string num="";
        for(int i=0;i<n;i++){
            int x = (s>=9)?(9):(s);
            s -= x;
            num += (char)('0'+x);
        }
        
        if(s>0) cout<<-1<<"\n";
        else cout<<num<<"\n";
        
    }
	return 0;
}