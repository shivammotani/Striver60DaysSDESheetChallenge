#include <bits/stdc++.h> 

void solve(vector<vector<int>> &ans,vector<vector<int>> &maze,vector<vector<int>> &board,int row, int col, int n){
    if(row == n-1 && col == n-1){
      board[row][col] = 1;
      vector<int> temp;
      for(int i=0; i<n; i++){
        for(int j=0;j<n;j++) temp.push_back(board[i][j]);
      }
      ans.push_back(temp);
      board[row][col] = 0;
      return; 
    }

    //Down
    if(row+1<n && board[row+1][col] == 0 && maze[row+1][col] == 1){
      board[row][col] = 1;
      solve(ans,maze,board,row+1,col,n);
      board[row][col] = 0;
    }

    //Left
    if(col-1>=0 && board[row][col-1] == 0 && maze[row][col-1] == 1){
      board[row][col] = 1;
      solve(ans,maze,board,row,col-1,n);
      board[row][col] = 0;
    }

    //Right
    if(col+1<n && board[row][col+1] == 0 && maze[row][col+1] == 1){
      board[row][col] = 1;
      solve(ans,maze,board,row,col+1,n);
      board[row][col] = 0;
    }

    //Up
    if(row-1>=0 && board[row-1][col] == 0 && maze[row-1][col] == 1){
      board[row][col] = 1;
      solve(ans,maze,board,row-1,col,n);
      board[row][col] = 0;
    }
}


vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    if(maze[0][0] == 1) solve(ans,maze,board,0,0,n);
    return ans;
}s