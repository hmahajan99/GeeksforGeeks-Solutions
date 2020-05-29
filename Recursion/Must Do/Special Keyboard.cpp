// Imagine you have a special keyboard with the following keys: 
// Key 1:  Prints 'A' on screen
// Key 2: (Ctrl-A): Select screen
// Key 3: (Ctrl-C): Copy selection to buffer
// Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. 
// If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. 
// That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).
// Print maximum number of A's. Print -1, if N is greater than 75.

// Approach: Recursion

// For N < 7, the output is N itself. (Observation)
// Ctrl V can be used multiple times to print current buffer. 
// The idea is to compute the optimal string length for N keystrokes by using a simple insight. 
// The sequence of N keystrokes which produces an optimal string length will end with a suffix of Ctrl-A, a Ctrl-C, followed by only Ctrl-V’s . (For N > 6)

#include<iostream>
using namespace std;

int arr[100]={0};
int dp[100];

// n -> AAAA(CtrlACV)(CtrlACVVVV)(CtrlACV+)
//     |_______________________|
//       Recursive Subproblem

int maxAs(int n){
    if(n<=6) return n;

    if(dp[n]!=-1) return dp[n];
    
    int ans=0;
    for(int b=n-3;b>=1;b--){
        int lenA = (n-b-1)*maxAs(b);
        ans = max(ans,lenA);
    }
    return dp[n]=ans;
}

int main(){
    
    fill(dp,dp+100,-1);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n>75) cout<<-1<<"\n";
        else cout<<maxAs(n)<<"\n";
    }
	return 0;
}