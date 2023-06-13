#include <bits/stdc++.h> 

void solve(vector<int> &num,vector<int> &ans, int i, int n, int sm){
    if (i == n) {
        ans.push_back(sm);
        return;
    }
    solve(num,ans,i+1,n,sm+num[i]);
    solve(num,ans,i+1,n,sm);
    
}


vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n=num.size();
    vector<int>ans;
    solve(num,ans,0,n,0);
    sort(ans.begin(), ans.end());
    return ans;
}