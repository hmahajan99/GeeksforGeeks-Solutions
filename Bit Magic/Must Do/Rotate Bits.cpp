// Given an integer N and an integer D, you are required to write a program to rotate the binary representation 
// of the integer N by D digits to the left as well as right and print the results in decimal values after each of the rotation.
// Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000.....001100.

// Example:
// Input:
// 1
// 229 3  [229 = 0b11100101]
// Output:
// 1832  [1832 = 0b11100101000]
// 40988  [40988 = 0b1010000000011100]

#include<iostream>
using namespace std;

int rotateLeft(int n,int d){
    // mask = 111....0000,  num of 1 = d , num of 0 & 1 = 16
    // mask = ((1<<16)-1)-((1<<(16-d))-1)
    int mask = (1<<16)-(1<<(16-d));  
    return ((n&mask)>>(16-d)) + (n<<d);
}

int rotateRight(int n,int d){
    // mask = 0000....111,  num of 1 = d , num of 0 & 1 = 16
    int mask = (1<<d)-1;  
    return ((n&mask)<<(16-d)) + (n>>d);
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        d%=16;
        cout<<rotateLeft(n,d)<<"\n";
        cout<<rotateRight(n,d)<<"\n";
    }
	return 0;
}

// Alternative: Without using mask
// IMP NOTE!!!!!!!!=> Hex number can be written as 0xffff
// Easy way of writing binary

#include<iostream>
using namespace std;

int rotateLeft(int n,int d){
    return (n<<d)|(n>>(16-d)); 
}

int rotateRight(int n,int d){
    return ((n<<(16-d))|(n>>d))&0xffff; // as n<<(16-d) might overflow 16 bits
}


int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned int n,d;
        cin>>n>>d;
        d%=16;
        cout<<rotateLeft(n,d)<<"\n";
        cout<<rotateRight(n,d)<<"\n";
    }
	return 0;
}