// Given arrival and departure times of all trains that reach a railway station. 
// Your task is to find the minimum number of platforms required for the railway station so that no train waits.

// Note: Consider that all the trains arrive on the same day and leave on the same day. 
// Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. 
// In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.
// Time intervals are in the 24-hour format(hhmm),  of the form HHMM

// Example:
// Input:
// 2
// 6 
// 0900  0940 0950  1100 1500 1800
// 0910 1200 1120 1130 1900 2000
// 3
// 0900 1100 1235
// 1000 1200 1240 

// Output:
// 3
// 1

// Approach 1: Brute force, O(n^2)
// The idea is to take every interval one by one and find the number of intervals that overlap with it. 
// Keep track of the maximum number of intervals that overlap with an interval. Finally, return the maximum value.

/***************************************************************************************************************************/

// Approach 2: MAXIMUM INTERVAL OVERLAP concept, O(n Log n)

// The idea is to consider all events in sorted order. 
// Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arrive(n),depart(n);
        for(int i=0;i<n;i++) cin>>arrive[i];
        for(int i=0;i<n;i++) cin>>depart[i];
        vector<pair<int,char>> v;        
        for(int i=0;i<n;i++){
            v.push_back({arrive[i],'a'}); 
            v.push_back({depart[i],'d'}); // For this question, if arrival & departure on same time, then arrival before departure
        }
        sort(v.begin(),v.end());    
        int platforms=0;
        int active=0;
        for(int i=0;i<v.size();i++){
            if(v[i].second=='a') active++; // arrival
            else active--;
            platforms=max(platforms,active);
        }
        cout<<platforms<<"\n";
    }
	return 0;
}