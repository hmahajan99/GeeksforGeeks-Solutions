// Eulerian Path is a path in graph that visits every edge exactly once. 
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 
// The task is to find that there exists the Euler Path or circuit or none in given undirected graph.
// Return the int value to print 1 if Euler path exists print 2 if Euler cycle exists else 0.

// Approach: Eulerian Circuit & Path in Undirected Graph, O(V+E) time

// A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path.

// Eulerian Cycle
// An undirected graph has Eulerian cycle if following two conditions are true.
// ….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
// ….b) All vertices have even degree.

// Eulerian Path
// An undirected graph has Eulerian Path if following two conditions are true.
// ….a) Same as condition (a) for Eulerian Cycle
// ….b) If 2 vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

// Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

/*Complete the function below*/

bool Graph::isConnected(){
    bool *vis = new bool[V]{0};
    
    queue<int> q;
    vis[0]=true;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    
    // Check if all non-zero degree vertices are visited 
    for(int i=0;i<V;i++){
        if(!vis[i]&&adj[i].size()>0) return false;
    }
    return true;
}

int Graph::isEulerian(){
    if(!isConnected()) return 0;
    
    int numOddDegVertices = 0;
    for(int i=0;i<V;i++){
        int deg = adj[i].size();
        if(deg%2) numOddDegVertices++;
    }
    
    if(numOddDegVertices==0) return 2; // eulerian 
    
    if(numOddDegVertices==2) return 1; // semi-eulerian
    
    return 0; // not Eulerian
    
}
