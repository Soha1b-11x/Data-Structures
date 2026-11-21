#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &arr, vector<pair<int,int>>&island, int sr, int sc, int br, int bc){
    arr[sr][sc] = 0; // mark as visited;
    vector<int>delrow = {0, -1, 0, 1};
    vector<int>delcol = {-1, 0, 1, 0};
    int row = arr.size(), col = arr[0].size();
    island.push_back({br-sr,bc-sc});

    for(int i=0;i<4;i++){
        int newRow = sr+delrow[i];
        int newCol = sc+delcol[i];
        if(newCol>=0 && newCol<col && newRow>=0 && newRow<row && arr[newRow][newCol]==1){
            dfs(arr, island, newRow, newCol, br, bc);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &arr){
    set<vector<pair<int,int>>>islands;
    int row = arr.size(), col = arr[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==1){
                vector<pair<int,int>>island;
                dfs(arr , island , i , j , i , j);
                islands.insert(island);
            }
        }
    }
    return islands.size();
}

int main() {

    // Test case 1  ->  expected output: 1
    vector<vector<int>> grid1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    cout << "Test 1: " << countDistinctIslands(grid1) << "  (expected 1)\n";

    // Test case 2  ->  expected output: 3
    vector<vector<int>> grid2 = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };
    cout << "Test 2: " << countDistinctIslands(grid2) << "  (expected 3)\n";

    return 0;
}