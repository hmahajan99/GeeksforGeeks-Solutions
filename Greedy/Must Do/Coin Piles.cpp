// There are N piles of coins each containing  Ai (1<=i<=N) coins.  
// Now, you have to adjust the number of coins in each pile such that for any two pile, 
// if a be the number of coins in first pile and b is the number of coins in second pile then |a-b|<=K. 
// In order to do that you can remove coins from different piles to decrease the number of coins in those piles but you cannot increase the number of coins in a pile by adding more coins. 
// Now, given a value of N and K, along with the sizes of the N different piles you have to tell the minimum number of coins to be removed in order to satisfy the given condition.
// Note: You can also remove a pile by removing all the coins of that pile.

// Example
// Input           
// 3 (test cases)
// 4 0 (n,k)
// 2 2 2 2 (A[i]..)
// 6 3
// 1 2 5 1 1 1
// 6 3
// 1 5 1 2 5 1
// Output        
// 0
// 1
// 2

// Approach 1: O(n^2)
// In order to find the minimum number of coins, we iterate over all the coin pile sizes,
// and for the rest of the piles if the pile size is less than the current size then remove that pile entirely 
// otherwise if the pile size is greater than current pile size plus K then remove the excess coins. 
// The minimum number of coins removed in any of the turns is the answer.  

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int removedPileCoins = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int extraCoinsRemoved = 0;
            for(int j=n-1;j>i;j--){
                extraCoinsRemoved += max(0,arr[j]-(arr[i]+k));
            } 
            ans = min(ans,removedPileCoins+extraCoinsRemoved);
            removedPileCoins += arr[i];
        }
        cout<<ans<<"\n";

    }

	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Optimizing Approach 1, O(nlogn) 
// Using cumulativeSum array to find extraCoinsRemoved in O(logn) for each i using upper_bound

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int cumSum[n]; // cumSum[i] = [sum j = n-1 to i] arr[j]
        cumSum[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--) cumSum[i] = arr[i] + cumSum[i+1]; 
        int removedPileCoins = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int extraCoinsRemoved = 0;
            int* it = upper_bound(arr+i+1,arr+n,arr[i]+k);
            if(it-arr<n){
                extraCoinsRemoved = cumSum[it-arr] - ((arr+n)-it)*(arr[i]+k);
            }
            ans = min(ans,removedPileCoins+extraCoinsRemoved);
            removedPileCoins += arr[i];
        }
        cout<<ans<<"\n";

    }

	return 0;
}
