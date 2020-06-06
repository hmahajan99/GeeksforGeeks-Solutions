// You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

// Approach 1: Count set bits in A^B, O(num_bits)

#include<iostream>
using namespace std;

int countSetBits(int n){
    int count=0;
    while(n){
        count += (n&1);
        n = n>>1;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<countSetBits(a^b)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Count set bits in A^B, O(num_set_bits) 
// n&(n-1) => remove last set bit

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
        int a,b;
        cin>>a>>b;
        cout<<countSetBits(a^b)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 3: Count set bits in A^B, O(num_set_bits) 
// n&(-n) => last set bit
// (n-(n&(-n))) => remove last set bit

#include<iostream>
using namespace std;

int countSetBits(int n){
    int count=0;
    while(n){
        count++;
        int p = n&(-n);
        n -= p;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<countSetBits(a^b)<<"\n";
    }
	return 0;
}
