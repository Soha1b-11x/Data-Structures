#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;

public:
    Graph(int vertex) {
        n = vertex;
        adj.resize(vertex);
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        // adj[v2].push_back(v1);   // remove this line for a directed graph
    }

    vector<int> topoSort() {
        int v=adj.size();
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
};

int main(){
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);


    // g.BFS();
    vector<int>topo = g.topoSort();
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }

    return 0;
}