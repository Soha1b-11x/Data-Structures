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

};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.print();
}