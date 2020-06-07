// Given a number N. The task is to find the length of the longest consecutive 1s in its binary representation.

// Approach 1: Loop over the bits

#include<iostream>
using namespace std;

int longestConsecutive1s(int n){
    int ans=0;
    while(n){
        int count = 0;
        while(n&1){
            count++;
            n = n>>1;
        }
        ans = max(ans,count);
        n = n>>1;
    }
    return ans;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<longestConsecutive1s(n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using  x = (x & (x << 1)) to reduce length of sequence by 1
// The operation x = (x & (x << 1)) reduces length of every sequence of 1s by one in binary representation of x. 
// If we keep doing this operation in a loop, we end up with x = 0. 
// The number of iterations required to reach 0 is actually length of the longest consecutive sequence of 1s.
//       11101111   (x)
//     & 11011110   (x << 1)
//     ----------
//       11001110   (x & (x << 1)) 
//         ^    ^
//         |    |
//    trailing 1 removed

#include<iostream>
using namespace std;

int longestConsecutive1s(int n){
    int ans = 0;
    while(n){
        n = (n & (n << 1)); 
        ans++;     
    }
    return ans;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<longestConsecutive1s(n)<<"\n";
    }
	return 0;
}