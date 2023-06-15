
  void solve(int i,int sum,int k,vector<int> &num,vector<vector<int>> &ans,vector<int> &temp){
    if(i==num.size()){
        if(sum==k)ans.push_back(temp);
          return ;
      }

    solve(i+1,sum,k,num,ans,temp);
    temp.push_back(num[i]);
    solve(i+1,sum+num[i],k,num,ans,temp);
    temp.pop_back();
    }

 
  vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,0,k,arr,ans,temp);
    return ans;
  }