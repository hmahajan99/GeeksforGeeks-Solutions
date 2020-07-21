// Given an array A[ ] and its size N your task is to complete two functions  a constructST  function which builds the segment tree  
// and a function RMQ which finds range minimum query in a segment tree .

void constructSTUtil(int *tree,int *arr,int index,int s,int e){
    if(s==e){
        tree[index] = arr[s];
        return;
    }
    
    // if(s>e) return; 

    int mid = (s+e)/2;
    constructSTUtil(tree,arr,2*index,s,mid);
    constructSTUtil(tree,arr,2*index+1,mid+1,e);

    int left = tree[2*index];
    int right = tree[2*index+1];
    tree[index]=min(left,right);
    
}

/* The functions which builds the segment tree */
int *constructST(int arr[],int n){
  int *tree = new int[4*n+1];
  constructSTUtil(tree,arr,1,0,n-1);
  return tree;
}

int query(int *tree,int index,int s,int e,int qs,int qe){
    
    // No overlap
    if(qe<s||qs>e) return INT_MAX;
    
    // Complete Overlap
    if(qs<=s&&qe>=e) return tree[index];

    // Partial Overlap
    int mid = (s+e)/2;
    int leftAns = query(tree,2*index,s,mid,qs,qe);
    int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);
    return min(leftAns,rightAns);
    
}

/* The functions returns the min element in the range from a and b */
int RMQ(int st[] , int n, int a, int b){
    return query(st,1,0,n-1,a,b);
}