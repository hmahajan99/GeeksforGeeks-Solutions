// Minimize the sum of product of two arrays with permutations allowed
// You are given two arrays, A and B, of equal size N. 
// The task is to find the minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], where shuffling of elements of arrays A and B is allowed.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 10^7
// 1 <= A[] <= 10^18

// Approach: Greedy, sorting
// Sort both the arrays A and B.
// Traverse the array and for each element, multiply A[i] and B[n – i – 1] and add to the total.

#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,greater<lli>()); // IMP NOTE: STL sort in descending order
        lli ans=0;
        for(int i=0;i<n;i++) ans+=a[i]*b[i];
        cout<<ans<<"\n";
    }
	return 0;
}