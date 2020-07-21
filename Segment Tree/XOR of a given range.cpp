// You are given an Array. Your task is to complete the function gtXor to return the XOR of the given range a and b.

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

/*Complete the function below*/
int gtXor(int arr[], int n,int a,int b){
    int *tree = new int[4*n+1];
    buildTree(tree,arr,1,0,n-1);
    return query(tree,1,0,n-1,a,b);
}

