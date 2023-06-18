#include <bits/stdc++.h> 
bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col){
    for(int k=0; k<n; k++){
        if(k != node && mat[k][node] == 1 && color[k] == col) return false;
    }  
    return true;
}

bool solve(int node, int color[], int m, int n, vector<vector<int>> &mat){
    if(node == n) return true;

    for(int i=1; i<=m; i++){
        if(isSafe(node, color, mat, n, i)){
            color[node] = i;
            if(solve(node+1,color,m,n,mat)) return true;
            color[node]= 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int nodes = mat.size();
    int color[nodes] = {0};
    if(solve(0,color,m,nodes,mat)) return "YES";
    return "NO";
}