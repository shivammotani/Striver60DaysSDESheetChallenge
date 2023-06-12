void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int flag = true;
        
        for(int i=0;i<r;i++){
            if(matrix[i][0] == 0) flag = false;
            for(int j=1;j<c;j++){
                if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(!flag) matrix[i][0] = 0;
        }
        
        
    }