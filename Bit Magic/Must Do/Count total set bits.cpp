// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Approach 1: A simple solution is to run a loop from 1 to n and sum the count of set bits in all numbers from 1 to n.

#include<iostream>
using namespace std;

int countSetBits(int n){
    int count=0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++) ans+=countSetBits(i);
        cout<<ans<<"\n";
    }
	return 0;
}