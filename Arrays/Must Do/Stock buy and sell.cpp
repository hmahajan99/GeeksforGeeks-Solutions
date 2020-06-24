// The cost of stock on each day is given in an array A[] of size N. 
// Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

// Example
// Input:
// 3
// 7
// 100 180 260 310 40 535 695
// 4
// 100 50 30 20
// 10
// 23 13 25 29 33 19 34 45 65 67

// Output:
// (0 3) (4 6)
// No Profit
// (1 4) (5 9)

// Approach

// Obviously, we need to sell when the prices are highest, and buy when prices are lowest.
// The Local Minima are the points of Lowest price and Local Maxima are the points of Highest price.

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
        
        bool sol=false;
        for(int i=0;i<n;i++){
            while(i<n-1&&a[i]>a[i+1]) i++;
            if(i<n-1){
                sol=true;
                int buy=i;
                while(i<n&&a[i]<a[i+1]) i++;
                cout<<"("<<buy<<" "<<min(i,n-1)<<") ";
            }
        }
        
        if(!sol) cout<<"No Profit";
        cout<<"\n";
        
        
    }
	return 0;
}