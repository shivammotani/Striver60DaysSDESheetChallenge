bool isValid(int matrix[9][9], int i, int j, int k){
    for(int loop = 0; loop<9; loop++){
        if(matrix[i][loop] == k) return false;
        if(matrix[loop][j] == k) return false;
        if(matrix[3*(i/3) + loop/3][3*(j/3) + loop%3] == k) return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(matrix[i][j] == 0){
                for(int k=1; k<=9; k++){
                    if(isValid(matrix,i,j,k)){
                        matrix[i][j] = k;
                        if(solve(matrix)) return true;
                        else matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}
