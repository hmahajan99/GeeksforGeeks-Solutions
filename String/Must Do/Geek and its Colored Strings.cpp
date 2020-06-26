// Geek loves to play with toys a lot. Once his parents bought him a new toy, that 'R', ‘B’ and ‘G’ characters. 
// His parents gave him a task, that was to make a string of size 'n'. Each character of the string is either ‘R’, ‘B’ or ‘G’. 
// In the final string there needs to be at least 'r' number of ‘R’, at least 'b' number of ‘B’ and at least 'g' number of ‘G’ (such that r + g + b <= n). 
// Geek being busy with some other work requested for your help to 
// find the count of all possible strings that can be formed using the given number of characters.

// Approach
// Remaining values = n -(r + b + g)
// Make all combinations for the remaining values
// Consider each element one by one for the remaining values and sum up all the permuations

#include<iostream>
#define lli long long
using namespace std;
int main(){
    lli fact[21]; 
    fact[0] = 1; 
    for(int i=1;i<=20;i++) fact[i] = fact[i-1]*i;     
    int t;
    cin>>t;
    while(t--){
        int n,r,g,b;
        cin>>n>>r>>g>>b;
        int left = n -(r+g+b); 
        lli ans = 0; 
      
        // Make all possible combinations of R, B and G for the remaining value 
        for (int i=0;i<=left;i++){ 
            for(int j=0;j<=left-i;j++){ 
                int k = left-(i+j); 
                ans = ans + fact[n]/(fact[i+r]*fact[j+b]*fact[k+g]); 
            } 
        }         
        
        cout<<ans<<"\n";
    }

	return 0;
}