// Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

#include<iostream>
#define lli long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    lli sum=0;
	    for(int i=0;i<n-1;i++){
	        lli x;
	        cin>>x;
	        sum+=x;
	    }
	    cout<<(n*(n+1))/2-sum<<"\n";
	}
	return 0;
}