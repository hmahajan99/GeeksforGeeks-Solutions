// Given an integer an N. 
// The task is to print the position of first set bit found from right side in the binary representation of the number.
// If there is no set bit print "0".

// Approach 1: Scan the number from right to see for set bits.

#include<iostream>
using namespace std;

int posFirstSetBit(int n){
    int pos=1;
    while(n){
        if(n&1) return pos;
        pos++;
        n = n>>1;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<posFirstSetBit(n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using n&-n to get last set bit from left
// answer = log2(n&-n)+1

#include<bits/stdc++.h>
using namespace std;

int posFirstSetBit(int n){
    if(n==0) return 0;

    int p = (n&(-n)); // Gives the last set bit from left
    return log2(p)+1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<posFirstSetBit(n)<<"\n";
    }
	return 0;
}