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
        adj[v2].push_back(v1);   // remove this line for a directed graph
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int j : adj[i])
                cout << j << " ";
            cout << endl;
        }
    }

    // BFS traversal
    void BFS(){
        queue<int>Q;
        vector<bool> isVisited(n , false);

        Q.push(0);
        isVisited[0] = true;

        while(!Q.empty()){
            int u = Q.front();
            Q.pop();

            cout<< u <<" -> ";
            for(int val : adj[u]){
                if(!isVisited[val]){
                    isVisited[val] = true;
                    Q.push(val);
                    cout<<val<<" ";
                }
            }
            cout<<endl;
        }
    }

    // DFS Treaversal 
    void dfsHelper(int u , vector<bool>& isVisited){
        cout<< u <<" ";
        isVisited[u] = true;

        for(int v : adj[u]){
            if(!isVisited[v]){
                dfsHelper(v , isVisited);
            }
        }
    }

    void DFS(){
        int src = 0;
        vector<bool>isVisited(n , false);
        dfsHelper(src , isVisited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    // g.print();
    // g.BFS();
    g.DFS();
}