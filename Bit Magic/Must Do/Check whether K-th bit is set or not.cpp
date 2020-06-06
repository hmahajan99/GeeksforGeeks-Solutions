// Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1. 
// Position of set bit '1' should be indexed starting with 0 from RSB side in binary representation of the number. 
// Consider N = 4(100):  0th bit = 0, 1st bit = 0, 2nd bit = 1

// Approach 1: Using Left Shift Operator

#include<iostream>
using namespace std;

bool isKthBitSet(int n,int k){
    return (n&(1<<k))>0 ? true : false; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(isKthBitSet(n,k)) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using Right Shift Operator

#include<iostream>
using namespace std;

bool isKthBitSet(int n,int k){
    return (n>>k)&1 ? true : false; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(isKthBitSet(n,k)) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}