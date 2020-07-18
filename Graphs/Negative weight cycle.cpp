// Given a graph, the task is to check if it contains a negative weight cycle or not.

// Approach: Bellman Ford Algorithm (Single Source Shortest Path) - Dynamic Programming
// Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
// Dijkstra’s algorithm is a Greedy algorithm and time complexity is O(ELogV). 
// Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. 
// But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

// How does this work? 
// Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. 
// It first calculates the shortest distances which have at-most one edge in the path. 
// Then, it calculates the shortest paths with at-most 2 edges, and so on. 
// After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. 
// There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. 
// If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle

#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V,E;

    // graph is represented as an array of edges.
    Edge* edgeList;
    
public:

    Graph(int V,int E){
        this->V=V;
        this->E=E;
        edgeList = new Edge[E];
    }
    
    void addEdge(int u,int v,int w,int idx){
        edgeList[idx].src=u;
        edgeList[idx].dest=v;
        edgeList[idx].weight=w;
    }
    
    int bellmanFord(int src){
        int dist[V];
        // Step 1: Initialize distances from src to all other vertices as INFINITE
        for (int i = 0; i < V; i++) dist[i] = INT_MAX;
        dist[src] = 0;

        // Step 2: Relax all edges |V| - 1 times. 
        // A simple shortest path from src to any other vertex can have atmost |V|-1 edges
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edgeList[j].src;
                int v = edgeList[j].dest;
                int weight = edgeList[j].weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Step 3: check for negative-weight cycles.  
        // The above step guarantees shortest distances if graph doesn't contain negative weight cycle.  
        // If we get a shorter path, then there is a cycle.
        for (int i = 0; i < E; i++) {
            int u = edgeList[i].src;
            int v = edgeList[i].dest;
            int weight = edgeList[i].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                // Graph contains negative weight cycle
                return 1;
            }
        }

        return 0; // Graph doesn't contain negative weight cycle

        
    }
    
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        Graph g(v,e);
        for(int i=0;i<e;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g.addEdge(u,v,w,i);
        }
        cout<<g.bellmanFord(0)<<"\n";
    }
	return 0;
}