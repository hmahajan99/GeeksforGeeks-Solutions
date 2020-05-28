// In a candy store there are N different types of candies available  and the prices of all the N different types of candies are provided to you.
// You are now provided with an attractive offer. You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to spend to buy all the N different candies. 
// Secondly, you have to tell what is the maximum amount of money you have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

// Approach: Greedy, sorting

#include<iostream>
#include<algorithm>
using namespace std;

int getMin(int a[],int n,int k){
    int i=0,j=n-1;
    int ans=0;
    while(i<=j){
        ans+=a[i++];
        j-=k;
    }
    return ans;
}

int getMax(int a[],int n,int k){
    int i=0,j=n-1;
    int ans=0;
    while(i<=j){
        ans+=a[j--];
        i+=k;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout<<getMin(a,n,k)<<" "<<getMax(a,n,k)<<"\n";
    }
	return 0;
}