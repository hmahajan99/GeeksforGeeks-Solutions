// Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. 
// The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

// Input: arr1[] = {10};
//        arr2[] = {2, 3};
// Output: arr1[] = {2}
//         arr2[] = {3, 10}  

// Input: arr1[] = {1, 5, 9, 10, 15, 20};
//        arr2[] = {2, 3, 8, 13};
// Output: arr1[] = {1, 2, 3, 5, 8, 9}
//         arr2[] = {10, 13, 15, 20} 

// Approach: O(1) extra space and O(NlogN + MlogM)
// Swap elements such that both arrays contain only those elements which are to be there in after the sorting of both the array.
// Now, sort both the array separately.

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int p[x],q[y];
        for(int i=0;i<x;i++) cin>>p[i];
        for(int i=0;i<y;i++) cin>>q[i];
        
        int i=0,j=0;
        for(int c=1;c<=x;c++){
            if(j==y||p[i]<q[j]) i++;
            else j++;
        }

        j--;
        while(j>=0){
            swap(p[i++],q[j--]);
        }
        sort(p,p+x);
        sort(q,q+y);
        for(int i=0;i<x;i++) cout<<p[i]<<" ";
        for(int i=0;i<y;i++) cout<<q[i]<<" ";
        cout<<"\n";

        
    }
    return 0;
}
