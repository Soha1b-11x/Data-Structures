#include <bits/stdc++.h>
using namespace std;

class graph{
    private:
    int n;
    vector<vector<int>>arr;

    public:
    
    graph(int vertex){
        n = vertex;
        arr.assign(vertex , vector<int>(vertex, 0));
    }

    void addEdge(int v , int u){
        arr[v][u] = 1;
        arr[u][v] = 1;
    }

    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // BFS in adjecency Matrix
    void BFS(){
        vector<int>arrBFS;
        vector<bool>isVis(n , false);
        queue<int>q;
        q.push(0);
        isVis[0] = true;

        while(!q.empty()){
            int src = q.front() ; 
            q.pop();
            arrBFS.push_back(src);
            for(int i=0;i<arr.size();i++){
                if(!isVis[i] && arr[src][i]==1){ //connected and not visited
                    isVis[i] = true;
                    q.push(i);
                }
            }
        }

        //print BFS
        cout<<"BFS traversal"<<endl;
        for(int i=0;i<arrBFS.size();i++){
            cout<<arrBFS[i]<<" ";
        }

    }

    // DFS in adjecency Matrix
    void DFS(){

    }
};

int main(){
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.print();
    g.BFS();
    return 0;
}