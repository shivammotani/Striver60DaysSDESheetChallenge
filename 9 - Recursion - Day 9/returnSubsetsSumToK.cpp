
void solve(vector<int> &arr,vector<vector<int>> &ans, int ind, int n, vector<int>&temp, int k, int sm){

  if (sm == k) {
    sort(temp.begin(), temp.end());
    ans.push_back(temp);
  }
    for(int i=ind; i<n; i++){
        if(i != ind && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(arr,ans,i+1,n,temp,k,sm+arr[i]);
        temp.pop_back();
    }
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
        // Write your code here.
    vector<vector<int>> ans;
    vector<int>temp;
    // sort(arr.begin(), arr.end());
    solve(arr,ans,0,n,temp,k, 0);
    return ans;
}