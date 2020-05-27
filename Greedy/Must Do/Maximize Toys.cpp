// Given an array consisting cost of toys. Given an integer K depicting the amount with you. 
// Maximise the number of toys you can have with K amount.

// Approach: Sorting, Greedy

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int i=0;
        while(i<n&&k>=arr[i]){
            k-=arr[i];
            i++;
        }
        cout<<i<<"\n";
    }
	return 0;
}