// Influenced by Social Networking sites, Rahul launches his own site Friendsbook. 
// Each user in Friendsbook is given a unique number, first user being numbered 1. 
// There are N users in Friendsbook numbered from 1 to N. 
// In Friendsbook, i th user can make j th user his friend without becoming his friend himself, i.e. in Friendsbook, there is a one-way link rather than a two-way link as in Facebook. 
// Moreover i th user can make j th user his friend iff i>j. Also one user should have no more and no less than one friend except user 1 who will have no friend. 
// Rahul wants to modify Friendsbook and find out whether one user is somehow linked to some other user. Help Rahul do so.

// Print all possible connections between the users in the following format: 
// 4 2 2 means 4 is linked to 2 via 2 connections.
// 5 2 3 means 5 is linked to 2 via 3 connections, and so on.
// The order of display should be as follows:
// Print all possible connections starting from user 2 to user N with other users starting from 1 to The Current User Number - 1. 
// In case one user is not connected at all with another user, that connection should not be printed.

// Approach 1: Using DFS

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
public:
    Graph(int v){
        V = v;
        adj = new list<int>[v];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void dfs(int node,list<int> &currentPath,int m[][505]){
        currentPath.push_back(node);
        for(int neighbour:adj[node]){
            dfs(neighbour,currentPath,m);
        }
        currentPath.pop_back();
        int dist=1;
        for(auto it=currentPath.rbegin();it!=currentPath.rend();it++){
            m[node][*it]=dist;
            dist++;
        }
    }
    
    void solve(){
        int m[505][505]={0}; // i linked to j via m[i][j] connections
        //bool *vis = new bool[V+1]{0}; dont need visited here since tree like structure
        list<int> currentPath;
        dfs(1,currentPath,m);
        for(int i=1;i<=V;i++){
            for(int j=1;j<i;j++){
                if(m[i][j]>0){
                    cout<<i<<" "<<j<<" "<<m[i][j]<<" "; 
                }
            }
        }
    }
    
    
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    Graph g(n+1);
	    for(int i=2;i<=n;i++){
	        int fr;
	        cin>>fr;
	        g.addEdge(fr,i); // fr -> i  (fr<i)
	    }
	    g.solve();
	    cout<<"\n";
	}
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Using Floyd Warshall

#include<bits/stdc++.h>
#define INF (int)(1e7)

using namespace std;

void floydWarshall(int A[][500],int v){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    
    // Print Soln
    for(int i=0;i<v;i++){
        for(int j=0;j<i;j++){
            if(A[i][j]!=INF){
                cout<<i+1<<" "<<j+1<<" "<<A[i][j]<<" ";  // 1 indexed            
            }
        }
    }
    
}


int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[500][500];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            A[i][j]=INF;
	        }
	    }
	    for(int i=2;i<=n;i++){
	        int fr;
	        cin>>fr;
	        A[i-1][fr-1]=1; // i -> fr  (fr<i)  Want 0 indexed
	        
	    }
	    floydWarshall(A,n);
	    cout<<"\n";
	}
	return 0;
}