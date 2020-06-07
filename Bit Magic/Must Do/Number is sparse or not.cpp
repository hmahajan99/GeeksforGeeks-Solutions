// Similar to Longest Consecutive 1’s

// Given a number N, check whether it is sparse or not. 
// A number is said to be a sparse number if in the binary representation of the number no two or more consecutive bits are set.

// Approach 1: Loop over the bits 

/***************************************************************************************************************************/

// Approach 2: Using  x = (x & (x << 1)) to reduce length of sequence of consecutive 1s by 1
//       11101111   (x)
//     & 11011110   (x << 1)
//     ----------
//       11001110   (x & (x << 1)) 
//         ^    ^
//         |    |
//    trailing 1 removed

#include<iostream>
using namespace std;

bool checkSparse(int n){ 
    if (n & (n>>1)) return false; 
    return true; 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<checkSparse(n)<<"\n";
    }
	return 0;
}