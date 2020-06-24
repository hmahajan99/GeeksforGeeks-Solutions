// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

// Approach 1: Brute Force, O(n^3)

/***************************************************************************************************************************/

// Approach 2: Using Hashmap, O(n^2)

/***************************************************************************************************************************/

// Approach 3: Sorting + 2 pointer, O(n^2) time & constant space

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=n-1;i>=2;i--){
            int j=0,k=i-1;
            while(j<k){
                if(a[j]+a[k]>a[i]) k--;
                else if(a[j]+a[k]<a[i]) j++;
                else {
                    ans++;
                    j++;
                    k--;
                }
            }
        }
        
        if(ans) cout<<ans<<"\n";
        else cout<<-1<<"\n";
    }
	return 0;
}