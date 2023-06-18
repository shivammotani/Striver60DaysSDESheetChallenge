#include<bits/stdc++.h>

int countNo(vector<int> &v, int no){
    int ans = 0;
    int low=0, high = v.size()-1;
    while(low <= high){
        int mid = low+high >> 1;
        if(v[mid] <= no) low = mid+1;
        else high = mid-1;
    }
    return  high+1;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();
    if(row == 1) return matrix[0][col/2];
    int low = INT_MAX, high = INT_MIN;
    for(int i=0; i<row; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][col-1]);
    }
    while(low<=high){
        int mid = low+high >> 1;
        int cnt = 0;
        for(int i=0; i<row; i++) cnt += countNo(matrix[i], mid);
        if(cnt<= (row*col)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}