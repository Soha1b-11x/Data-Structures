#include <bits/stdc++.h>
using namespace std;

// unDirected weighted graph
void unDirected_Weigted_Graph(){
    int vertex , edges;
    cout << "Enter vertex and edges" <<endl;
    cin>>vertex >> edges;

    vector<vector<int>>adjMat(vertex , vector<int>(vertex , 0)); // matrix
    int u , v , weight;
    for(int i=0;i<edges;i++){
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }

    //print matrix
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adjMat[i][j] <<" ";
        }
        cout<<endl;
    }
}

// undirected unweigted graph
void undirected_unWeighted_Graph(){
    int vertex , edges;
    cout << "Enter vertex and edges" <<endl;
    cin>>vertex >> edges;

    vector<vector<bool>>adjMat(vertex , vector<bool>(vertex , 0)); // matrix
    int u , v;
    for(int i=0;i<edges;i++){
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    //print matrix
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adjMat[i][j] <<" ";
        }
        cout<<endl;
    }

}

// directed unweighted graph
void directed_unWeighted_Graph(){
    int vertex , edges;
    cout << "Enter vertex and edges" <<endl;
    cin>>vertex >> edges;

    vector<vector<bool>>adjMat(vertex , vector<bool>(vertex , 0)); // matrix
    int u , v;
    for(int i=0;i<edges;i++){
        cin >> u >> v;
        adjMat[u][v] = 1;
    }

    //print matrix
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adjMat[i][j] <<" ";
        }
        cout<<endl;
    }
}

// directed weighted graph
void directed_weighted_Graph(){
    int vertex , edges;
    cout << "Enter vertex and edges" <<endl;
    cin>>vertex >> edges;

    vector<vector<int>>adjMat(vertex , vector<int>(vertex , 0)); // matrix
    int u , v , weight;
    for(int i=0;i<edges;i++){
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;
    }

    //print matrix
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adjMat[i][j] <<" ";
        }
        cout<<endl;
    }

}

int main(){

    unDirected_Weigted_Graph();
    undirected_unWeighted_Graph();
    directed_unWeighted_Graph();
    directed_weighted_Graph();

    return 0;
}