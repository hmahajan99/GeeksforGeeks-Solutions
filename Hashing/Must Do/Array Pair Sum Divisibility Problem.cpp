// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs 
// such that sum of every pair is divisible by k.

// Approach 1: Brute Force
// A Simple Solution is to iterate through every element arr[i]. 
// Find if there is another not yet visited element that has remainder as (k – arr[i]%k). 
// If there is no such element, return false. If a pair is found, then mark both elements as visited.
// Time complexity of this solution is O(n^2) and it requires O(n) extra space.

/***************************************************************************************************************************/

// Approach 2: Using Hashing

// 1) If length of given array is odd, return false. An odd length array cannot be divided into pairs.
// 2) Traverse input array and count occurrences of all reminders. freq[arr[i] % k]++
// 3) Traverse input array again. 
//    a) Find the remainder of the current element.
//    b) If remainder divides k into two halves, then there must be even occurrences of it as it forms pair with itself only.
//    c) If the remainder is 0, then there must be even occurrences.
//    c) Else, number of occurrences of current the remainder must be equal to a number of occurrences of "k - current remainder".

#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int k;
        cin>>k;

        if(n&1){
            cout<<"False\n";
            continue;
        }

        unordered_map<int,int> freqRem;
        for(int i=0;i<n;i++){
            freqRem[a[i]%k]++;
        }
        
        bool sol=true;
        
        for(int i=0;i<n;i++){
            int rem = a[i]%k;
            
            if (2*rem == k){ 
                if(freqRem[rem]&1) sol = false; 
            }else if (rem == 0){ 
                if(freqRem[rem]&1) sol = false; 
            }else if (freqRem[rem] != freqRem[k - rem]){ 
                sol = false;             
            }
            
            if(!sol) break;
            
        }
        

        if(sol) cout<<"True\n";
        else cout<<"False\n";

    }

	return 0;

    
}