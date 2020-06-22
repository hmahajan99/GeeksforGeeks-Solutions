// Given an array A[] of integers, sort the array according to frequency of elements. 
// That is elements that have higher frequency come first. 
// If frequencies of two elements are same, then smaller number comes first.

// Approach 1: Using Custom Comparator 
// NOTE: STL Lambda

#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        unordered_map<int,int> freq;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        } 

        // NOTE: STL Lambda
        sort(a,a+n,[&freq](int a,int b){  
            return freq[a]>freq[b] || (freq[a]==freq[b]&&a<b);
        });

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        

    }
	return 0;
}