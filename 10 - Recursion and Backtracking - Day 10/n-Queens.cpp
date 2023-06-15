bool canBePlaced(int row, int col, vector<vector<int>> &board, int n){
    int dupRow = row;
    int dupCol = col;

    while(dupCol >=0 && dupRow >=0) if(board[dupRow--][dupCol--] == 1) return false;
    dupCol = col;
    while(dupCol >=0) if(board[row][dupCol--] == 1) return false;
    while(row <n && col >=0) if(board[row++][col--] == 1) return false;
    return true;

}
void solve(vector<vector<int>> &ans,vector<vector<int>> &board,int ind, int n){
    if(ind==n){
        vector<int> temp;
        for(int r=0; r<n; r++){
            for(int j=0;j<n;j++) temp.push_back(board[r][j]);
        }  

        ans.push_back(temp);
        return;
    }

    for(int r=0; r<n; r++){
        if(canBePlaced(r,ind,board,n)){
            board[r][ind] = 1;
            solve(ans,board,ind+1,n);
            board[r][ind] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here0
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(ans,board,0,n);
    return ans;
}