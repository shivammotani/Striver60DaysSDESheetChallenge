vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      if(i==0 || j==0){
        vector<long long int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        continue;
      }
      else if(i == j) ans[i].push_back(1);
      else{
        ans[i].push_back(ans[i-1][j] + ans[i-1][j-1] );
      }
    }
  }
  return ans;
}