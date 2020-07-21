// Nitika recently read about XOR operation and she got obssessed with it. She has an array containing N Positive integers.
// She wants to perform Q queries on the array.
// In a query She gives two integers L and R.(1 based indexing).
// Now, she asks what is the xor of all the elements of the array after not including the subarray ranging from L to R (both inclusive).
// Nitika guarantees that in each query, The resulting array is non empty.

// Approach 1: Segment Tree, O(logn) for each query

#include<iostream>
using namespace std;

int buildTree(int *tree,int *arr,int index,int s,int e){

    if(s==e) return tree[index] = arr[s];

    int mid = (s+e)/2;
    return tree[index] = buildTree(tree,arr,2*index,s,mid) ^ buildTree(tree,arr,2*index+1,mid+1,e);

}

int query(int *tree,int index,int s,int e,int qs,int qe){
    
    if(qe<s||qs>e) return 0;

    if(qs<=s&&qe>=e) return tree[index];

    int mid = (s+e)/2;
    int leftAns = query(tree,2*index,s,mid,qs,qe);
    int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);
    return leftAns ^ rightAns;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int xorAll = 0;
        for(int i=0;i<n;i++) xorAll=xorAll^arr[i];
        
        int *tree = new int[4*n+1];
        buildTree(tree,arr,1,0,n-1);
        while(q--){
            int l,r;
            cin>>l>>r;
            l--; r--;
            cout<<(query(tree,1,0,n-1,l,r)^xorAll)<<"\n";
        }
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Precompute Prefix XOR array, O(1) for each query

#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int prefixXor[n+1];
        prefixXor[0]=0;
        for(int i=0;i<n;i++){
            prefixXor[i+1]=prefixXor[i]^arr[i];
        } 
        int xorAll = prefixXor[n];
        
        while(q--){
            int l,r;
            cin>>l>>r;
            l--; r--;
            int subArrayXor = prefixXor[r+1] ^ prefixXor[l];
            cout<<(subArrayXor^xorAll)<<"\n";
        }
    }
	return 0;
}