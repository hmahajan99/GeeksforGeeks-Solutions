// Given a snake and ladder board of order 5x6, 
// find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 
// The first line of input contains an integer N denoting the no of ladders and snakes present. 
// Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

using namespace std;

class Graph{
  int V;
  list<int> *adj;
  public:
  Graph(int v){
      V=v;
      adj = new list<int>[V+1];
  }
  void addEdge(int u,int v){
      adj[u].push_back(v);
  }
  int bfs(int src,int dest){
      bool *vis=new bool[V+1]{0};
      int *dist=new int[V+1];
      queue<int> q;
      vis[src]=true;
      dist[src]=0;
      q.push(src);
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=true;
                dist[neighbour]=dist[node]+1;
                q.push(neighbour);
            }              
          }
      }
      return dist[dest];
  }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int board[31]={0};
	    int n;
	    cin>>n;
	    for(int i=1;i<=30;i++){
            board[i]=i;
	    }
	    for(int i=0;i<n;i++){
	        int a,b;
	        cin>>a>>b;
	        board[a]=b;
	    }
	    Graph g(30);
	    for(int u=0;u<=30;u++){
	        for(int dice=1;dice<=6;dice++){
	            if(u+dice<=30){
                    g.addEdge(u,board[u+dice]);
	            }
	        }
	    }
	    cout<<g.bfs(1,30)<<"\n";
	}
	
	return 0;
}