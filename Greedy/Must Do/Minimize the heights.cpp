// Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower 
// either by increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.

// Example
// Input  : A[] = {1, 15, 10}, k = 6
// Output : 5
// Explanation : We change 1 to 7, 15 to 9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference

// Approach: O(n) solution
// Minimize the maximum difference between the heights

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        pair<int*,int*> minMax = minmax_element(arr,arr+n); // IMP NOTE: STL minmax_element 
        int mn = *(minMax.first), mx = *(minMax.second); 
        if(mx-mn<=k){
            cout<<mx-mn<<"\n"; // add (or subtract) k in all
        }else{
            int s = min(mn+k,mx-k);
            int e = max(mn+k,mx-k);
            for(int i=0;i<n;i++){
                // Either subtraction causes a smaller number or addition causes a greater number. 
                // Update small(s) or big(e) using greedy approach 
                // If big - subtract causes smaller diff, update small Else update big                 
                int a = arr[i]-k, b = arr[i]+k;
                if((s<=a)||(b<=e)) continue;
                
                if(s-a<=b-e) s = a;
                else e = b;
                
            }
            
            cout<<e-s<<"\n";
            
        }
        
    }
    
	return 0;
}