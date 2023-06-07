bool searchMatrix(vector<vector<int>>& mat, int target) {
    int r = mat.size();
    int c = mat[0].size();
    int i = 0, j = c-1;
    while(i<r && j>=0 ){
        if(mat[i][j] == target) return true;
        else if(mat[i][j] < target) i++;
        else j--;
    }
    return false;
}

OR 

bool searchMatrix(vector<vector<int>>& mat, int target) {
    if(!mat.size()) return false;
    int rows = mat.size();
    int cols = mat[0].size();
    if(rows == 1 && cols == 1 && mat[0][0] == target) return true;
    int low = 0, high = (rows*cols) -1 ;
    while(low <= high){ 
        int mid = low+((high - low) / 2);
        if(mat[mid/cols][mid%cols] == target) return true;
        else if (mat[mid/cols][mid%cols] < target) low = mid +1; 
        else high = mid-1;
    }
    return false;
}
