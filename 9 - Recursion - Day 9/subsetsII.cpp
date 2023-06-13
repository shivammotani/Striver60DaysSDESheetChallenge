#include <bits/stdc++.h> 

void solve(vector<int> &arr,vector<vector<int>> &ans, int ind, int n, vector<int>&temp){
    ans.push_back(temp);
    for(int i=ind; i<n; i++){
        if(i != ind && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(arr,ans,i+1,n,temp);
        temp.pop_back();
    }
}



vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int>temp;
    sort(arr.begin(), arr.end());
    solve(arr,ans,0,n,temp);
    return ans;

}