// Given a non-negative number N and two values L and R. 
// The problem is to toggle the bits in the range L to R in the binary representation of N, i.e, to toggle bits 
// from the rightmost Lth bit to the rightmost Rth bit. 
// A toggle operation flips a bit 0 to 1 and a bit 1 to 0.

// Approach: XOR
// Calculate num as = ((1 << r) – 1) ^ ((1 << (l-1)) – 1) 
// This will produce a number num having r number of bits and bits in the range l to r are the only set bits.
// Now, perform n = n ^ num. This will toggle the bits in the range l to r in n.

#include<iostream>
using namespace std;

int toggleBitsInRange(int n,int l,int r){
    // l,r are 0-indexed i.e for rightmost bit, l=0
    int mask = (1<<(r+1)) - (1<<l);
    return n^mask;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        cout<<toggleBitsInRange(n,l-1,r-1)<<"\n"; 
    }
	return 0;
}