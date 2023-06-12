vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   unordered_map<int,int> mp;
   vector<vector<int>> ans;

   for(int i=0; i<arr.size(); i++){
      int target = s-arr[i];
      if(mp.find(target) != mp.end()){
         int loop = mp[target];
         while(loop--){
            vector<int> temp;
            temp.push_back(target);
            temp.push_back(arr[i]);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
         }
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}