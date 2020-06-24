// Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a^2 + b^2 = c^2

// Approach 1: Brute Force, O(n^3)

/***************************************************************************************************************************/

// Approach 2: Using Hashmap, O(n^2)

/***************************************************************************************************************************/

// Approach 3: Sorting + 2 pointer, O(n^2) time & constant space

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    FIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]*=a[i];
        } 
        sort(a,a+n);
        bool sol=false;
        for(int i=n-1;i>=2;i--){
            int j=0,k=i-1;
            while(j<k){
                if(a[j]+a[k]>a[i]) k--;
                else if(a[j]+a[k]<a[i]) j++;
                else {
                    sol = true;
                    break;
                }
            }
            if(sol) break;
        }
        
        if(sol) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}