// Given an unsorted array of size N. 
// Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.
// Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int maxLeft[n],minRight[n];
        maxLeft[0]=a[0];
        for(int i=1;i<n;i++) maxLeft[i]=max(maxLeft[i-1],a[i]);
        minRight[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) minRight[i]=min(minRight[i+1],a[i]);
        bool sol=false;
        for(int i=1;i<n-1;i++){
            if(maxLeft[i]<=a[i]&&a[i]<=minRight[i]){
                sol = true;
                cout<<a[i]<<"\n";
                break;
            }
        }
        if(!sol) cout<<-1<<"\n";
    }
    
	return 0;
}