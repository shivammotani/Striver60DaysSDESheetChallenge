#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    if(grid.empty()) return 0;
    int ans = 0,cntFresh = 0, cnt = 0;
    int row = grid.size();
    int col = grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    int v[row][col];

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j] == 2){
              q.push({{i, j}, 0});
              v[i][j] = 2;
            }
            else{
                if(grid[i][j] == 1) cntFresh++;
                v[i][j] = 0;
            } 
        }
    }

    while(!q.empty()){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        ans = max(ans,t);
        q.pop();
        for(int i=0; i<4; i++){
            int rdrow = r + drow[i];
            int ccol = c + dcol[i];
            if(rdrow>=0 && rdrow<row && ccol>=0 && ccol<col && v[rdrow][ccol] != 2 && grid[rdrow][ccol] == 1){
                q.push({{rdrow,ccol},t+1});
                v[rdrow][ccol] = 2;
                cnt++;
            }
        }

    }

    if(cnt != cntFresh) return -1;
    return ans;



}