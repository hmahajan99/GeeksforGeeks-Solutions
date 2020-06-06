// Given two numbers M and N. The task is to find the position of rightmost different bit in binary representation of numbers.
// If both M and N are same then print -1 in this case.
// Example: 11 9
// Binary representaion of the given numbers are: 1011 and 1001, 2nd bit from right is different.

// Approach 1: Use XOR
// Scan the number from right to see for set bits.

#include<bits/stdc++.h>
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
        int m,n;
        cin>>m>>n;
        cout<<posFirstSetBit(m^n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using n&-n to get last set bit from left
// answer = log2(x&-x)+1 , x = m^n

#include<bits/stdc++.h>
using namespace std;

int posFirstSetBit(int n){
    if(n==0) return -1;

    int p = (n&(-n)); // Gives the last set bit from left
    return log2(p)+1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<posFirstSetBit(m^n)<<"\n";
    }
	return 0;
}
