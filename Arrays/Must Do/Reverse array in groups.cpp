// Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

#include<bits/stdc++.h>
#define lli long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        lli A[n];
        for(int i=0;i<n;i++) cin>>A[i];
        for(int i=0;i<n;i+=k){
            int x = min(i+k,n);
            reverse(A+i,A+x); // STL reverse
        }
        for(int i=0;i<n;i++) cout<<A[i]<<" ";
        cout<<"\n";
    }
	return 0;
}