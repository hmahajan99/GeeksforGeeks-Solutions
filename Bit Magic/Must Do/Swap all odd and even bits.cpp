// Given an unsigned integer N. The task is to swap all odd bits with even bits. 
// For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
// Here, every even position bit is swapped with adjacent bit on right side, 
// and every odd position bit is swapped with adjacent on left side.

// Approach: Using Hex numbers 0xAAAAAAAA and 0x55555555 as mask to isolate odd & even bits
// IMP NOTE!!!!!!!!=> Hex number can be written as 0xffff
// Easy way of writing binary

// We basically need to right shift (>>) all even bits by 1 so that they become odd bits (highlighted in 43), 
// and left shift (<<) all odd bits by 1 so that they become even bits. 
// The solution assumes that input number is stored using 32 bits.
// Let the input number be x
// 1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
// 2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
// 3) Right shift all even bits.
// 4) Left shift all odd bits.
// 5) Combine new even and odd bits and return.

#include<iostream>
using namespace std;

int swapOddEvenBits(int n){
    int evenBits = n&0xAAAAAAAA;  // 32 bits
    int oddBits = n&0x55555555;  // 32 bits
    return (evenBits>>1)|(oddBits<<1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<swapOddEvenBits(n)<<"\n";
    }
	return 0;
}