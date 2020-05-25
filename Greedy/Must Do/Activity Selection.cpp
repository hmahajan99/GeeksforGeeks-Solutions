// Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Note : The start time and end time of two activities may coincide.

// Approach: Greedy, sorting
// The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin>>v[i].first;
        for(int i=0;i<n;i++) cin>>v[i].second;
        sort(v.begin(),v.end(),cmp);
        int time=0,ans=0;
        for(int i=0;i<n;i++){
            if(v[i].first>=time){
                time=v[i].second;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    
	return 0;
}