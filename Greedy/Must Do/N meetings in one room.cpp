// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room?
// Same as Activity Selection
// Example:
// Input:
// 1
// 6
// 1 3 0 5 8 5
// 2 4 6 7 9 9
// Output:
// 1 2 4 5

// Approach: Greedy, sorting
// The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int s,f,i;
};

bool cmp(Node a, Node b){
    return a.f<b.f;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<Node> v(n);
        for(int i=0;i<n;i++) v[i].i=i;
        for(int i=0;i<n;i++) cin>>v[i].s;
        for(int i=0;i<n;i++) cin>>v[i].f;
        sort(v.begin(),v.end(),cmp);
        int time=0;
        for(int i=0;i<n;i++){
            if(v[i].s>=time){
                time=v[i].f;
                cout<<v[i].i+1<<" "; // want 1 indexed
            }
        }
        cout<<"\n";
    }
    
	return 0;
}