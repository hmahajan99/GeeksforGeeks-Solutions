// Given an input stream of N integers. 
// The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

// Note that output is effective median of integers read from the stream so far. 
// Such an algorithm is called online algorithm. 
// Any algorithm that can guarantee output of i-elements after processing i-th element, is said to be online algorithm. 

// Approach 1: Insertion Sort
// If we can sort the data as it appears, we can easily locate median element. Insertion Sort is one such online algorithm that sorts the data appeared so far. 
// O(n^2) time 

/***************************************************************************************************************************/

// Approach 2: Using Heaps / Self Balancing BST
// The idea is to use one max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time.
// If num of elements is even size of both are equal
// If num of elements is odd size of max heap for lower half is greater by 1

// Time Complexity: O(n Log n)
// Auxiliary Space : O(n)

#include<iostream>
#include<queue>
using namespace std;

class Comp{
  public:
  bool operator()(int a,int b){
      return a>b;
  }
};

int main(){
	int n;
	cin>>n;
	priority_queue<int> lMax;
// 	priority_queue<int,vector<int>,Comp> rMin; 
	priority_queue<int,vector<int>,greater<int>> rMin; // Same thing
	for(int i=1;i<=n;i++){
	    int x;
	    cin>>x;
	    if(i==1||x<lMax.top()){
	        lMax.push(x);
	    }else{
	        rMin.push(x);
	    }
	    
	    if(i%2==0){
	        if(lMax.size()==rMin.size()+2){
	            rMin.push(lMax.top());
	            lMax.pop();
	        }
	        cout<<(lMax.top()+rMin.top())/2<<"\n";
	    }
	    
	    if(i%2==1){
	        if(lMax.size()+1==rMin.size()){
	            lMax.push(rMin.top());
	            rMin.pop();
	        }
	        cout<<lMax.top()<<"\n";
	    }

	}
	return 0;
}