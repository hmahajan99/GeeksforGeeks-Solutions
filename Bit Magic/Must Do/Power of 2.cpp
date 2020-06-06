// Given a positive integer N. The task is to check if N is a power of 2. That is N is 2^x for some x.

// Approach 1: Count of Set Bits = 1 using n&(-n)
// n&(-n) => last set bit
// (n-(n&(-n))) => remove last set bit
// (n-(n&(-n))) == 0 for power of 2

#include<iostream>
#define lli long long
using namespace std;


bool isPowerOfTwo(lli n){
    if(n==0) return false;
    return (n-(n&(-n))) == 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        if(isPowerOfTwo(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Count of Set Bits = 1 using n&(n-1)
// n&(n-1) => remove last set bit

#include<iostream>
#define lli long long
using namespace std;


bool isPowerOfTwo(lli n){
    if(n==0) return false;
    return (n&(n-1)) == 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        if(isPowerOfTwo(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 3: Using LOG2 in CMATH => returns double
// LOG2 is an integer for power of 2

#include<iostream>
#include<cmath>
#define lli long long
using namespace std;


bool isPowerOfTwo(lli n){
    if(n==0) return false;
    return log2(n) == (lli) log2(n);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        if(isPowerOfTwo(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 4: Repeated division by 2
// Keep dividing the number by two, i.e, do n = n/2 iteratively. 
// In any iteration, if n%2 becomes non-zero and n is not 1 then n is not a power of 2. If n becomes 1 then it is a power of 2.
