// Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges
// So, we have to determine what is the minimum time required to rot all oranges. 
// A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
// If it is impossible to rot every orange then simply return -1.

// Approach 1: Brute Force
// Traverse through all oranges in multiple rounds. In every round, rot all adjacent of oranges which were rotten in last round.
// Time Complexity : O(Ans * R *C) where Ans is number of rounds required to rot all oranges. 

/***************************************************************************************************************************/

// Approach 2: Using BFS
// Find all rotten oranges and enqueue them to Q.
// Time Complexity : O(R x C)

#include<bits/stdc++.h>
using namespace std;

class QueueNode{
public:
    int x;
    int y;
    int day;
    QueueNode(int i,int j,int d): x(i),y(j),day(d) {} 
};

bool isValid(int x,int y,int r,int c){
    if(x<0||x>=r||y<0||y>=c) return false;
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int m[r][c];
        queue<QueueNode> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>m[i][j];
                if(m[i][j]==2) q.push({i,j,0});
            }
        }
        
        int ans=0;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        // BFS
        while(!q.empty()){
            QueueNode front = q.front();
            q.pop();
            ans=max(ans,front.day);
            for(int k=0;k<4;k++){
                int x=front.x+dx[k],y=front.y+dy[k];
                if(isValid(x,y,r,c)&&m[x][y]==1){
                    m[x][y]=2;
                    q.push({x,y,front.day+1});
                }
            }
        }
        
        // Check if fresh apple still left 
        bool freshApplePresent=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==1){
                    freshApplePresent=true;
                    break;
                } 
            }
            if(freshApplePresent) break;
        }
        
        if(freshApplePresent) cout<<-1<<"\n";
        else cout<<ans<<"\n";

    }
	return 0;
}