// See InterviewBit-Solutions/Graphs/Graph connectivity/Commutable Islands.cpp

// Given a weighted, undirected and connected graph. 
// The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
// Constraints:
// Graph is connected and doesn't contain self loops & multiple edges.

// Approach 1: Prims algorithm
// If the input graph is represented using adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap.

// Function to construct and print MST for a graph represented using adjacency matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<list<pair<int,int>>> adjList(V);
    for(int u=0;u<V;u++){
        for(int v=0;v<V;v++){
            int weight=graph[u][v];
            if(weight!=INT_MAX) adjList[u].push_back({v,weight});
        }
    }
    
    vector<bool> inMST(V,false); // Visited array
    vector<int> key(V,INT_MAX);
    vector<int> parent(V,-1);
    set<pair<int,int>> s;
    key[0]=0;
    s.insert({key[0],0});
    while(!s.empty()){
        int minWeightVertex = s.begin()->second;
        s.erase(s.begin());
        inMST[minWeightVertex] = true;  
        for(auto p:adjList[minWeightVertex]){
            int v=p.first, cost=p.second;
            if(!inMST[v]&&cost<key[v]){
                auto it = s.find({key[v],v});
                if(it!=s.end()) s.erase(it);
                s.insert({cost,v});
                key[v]=cost;
                parent[v]=minWeightVertex;
            }
        }
    }

    int costMST=0;
    for(int k:key) costMST+=k;
    return costMST;
}