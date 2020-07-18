// The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
// The Graph is represented as Adjancency Matrix, and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

// Approach: Floyd Warshall Algorithm (All Pairs Shortest Path) - Dynamic Programming

// The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem (Dynamic Programming, optimal substructure property)
// Time Complexity: O(V^3)
// We can use Dijskstra’s shortest path algorithm for finding all pair shortest paths by running it for every vertex. Time complexity (V^3).
// Floyd Warshall works for negative edge but no negative cycle, whereas Dijkstra’s algorithm don’t work for negative edges.
// Time Complexity of Dijkstra’s Algorithm: The time complexity for the matrix representation is O(V^2). For adjacency list representation O(ELogV) algorithm.
// Time Complexity of Floyd Warshall: O(V^3)

// Floyd Warshall Algorithm
// We initialize the solution matrix same as the input graph matrix as a first step. 
// Then we update the solution matrix by considering all vertices as an intermediate vertex. 
// The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
// When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. 
// For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
// 1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
// 2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
// The following figure shows the above optimal substructure property in the all-pairs shortest path problem.

// Can use Floyd Warshall for Detecting negative cycle 

#define INF (int)(1e7)
using namespace std;

void floydWarshall(int** A,int v){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    
    // Print Soln
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            (A[i][j]==INF)?(cout<<"INF "):(cout<<A[i][j]<<" ");
        }
        cout<<"\n";
    }
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
        int v;
        cin>>v;
        int** adjMatrix;
        adjMatrix = new int*[v];
        for(int i=0;i<v;i++){
            adjMatrix[i]=new int[v];
        }
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cin>>adjMatrix[i][j];
            }
        }
        floydWarshall(adjMatrix,v);
	}
	return 0;
}