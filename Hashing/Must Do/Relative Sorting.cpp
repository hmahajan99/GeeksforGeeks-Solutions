// Given two arrays A1[] and A2[] of size N and M respectively. 
// The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. 
// For the elements not present in A2, append them at last in sorted order. 
// It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

// Example:
// Input:
// 2
// 11 4
// 2 1 2 5 7 1 9 3 6 8 8
// 2 1 8 3
// 8 4
// 2 6 7 5 2 6 8 4 
// 2 6 4 5
// Output:
// 2 2 1 1 8 8 3 5 6 7 9
// 2 2 6 6 4 5 7 8

// Approach 1: Using Custom Comparator 
// NOTE: STL Lambda

#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        unordered_map<int,int> priority;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++){
            int b;
            cin>>b;
            priority[b]=i+1;
        }

        // NOTE: STL Lambda, & => captures everything (need to capture priority), OR could make priority global        
        sort(a,a+n,[&](int a,int b){  
            int p1 = priority[a], p2 = priority[b];
            if(p1&&p2) return p1<p2;
            else if(p1) return true;
            else if(p2) return false;
            else return a<b;
        });

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        

    }
	return 0;
}