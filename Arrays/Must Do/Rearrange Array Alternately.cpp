// Given a sorted array of positive integers. 
// Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, 
// third should be second max, fourth should be second min and so on...
// Note: O(1) extra space is allowed. Also, try to modify the input array as required.

// Constraints:
// 1 <=T<= 100
// 1 <=N<= 107
// 1 <=arr[i]<= 107

// Example:
// Input:
// 2
// 6
// 1 2 3 4 5 6
// 11 
// 10 20 30 40 50 60 70 80 90 100 110

// Output:
// 6 1 5 2 4 3
// 110 10 100 20 90 30 80 40 70 50 60

// Approach: Encoding 2 numbers into 1 (num = old + M*new)
// The idea is to use multiplication and modular trick to store two elements at an index.
// For Rearranging array, we need to store a new value at the position of old value, but do not want to lose the old value too.
// Also, we cannot use extra space for this operation (else it would not be Rearrangement and is very easy to execute).
// Here, We will store both new value and old value at same position.
// Here, We will use the formula Dividend = Divisor * Quotient + Remainder
// Divisor is a value which is higher than values stored in array (in this case n - size of array, as array elements are between 0 to n-1)
// Obviously, don't forget to remove the multiplier n from the values while accessing and outputting the new values.

#include<iostream>
#define lli long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        lli M = 1e9+7;
        for(int i=0;i<n/2;i++) a[2*i+1]+=M*(a[i]%M);
        for(int i=n-1;i>=n/2;i--) a[2*(n-1-i)]+=M*(a[i]%M);
        for(int i=0;i<n;i++) a[i]/=M;
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
 
	return 0;
}