// Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. 
// The position of LSB(or last bit) is 0, second last bit is 1 and so on. 
// Also, 0 <= K < X, where X is the number of bits in the binary representation of N.

// Approach: Bitwise OR | operator
// To set any bit we use bitwise OR | operator.
// In general, (1 << k) | n

#include<iostream>
using namespace std;

int setKthBitSet(int n,int k){
   return n|(1<<k); 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<setKthBitSet(n,k)<<"\n";
    }
	return 0;
}