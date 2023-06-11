#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
        unordered_map<int,int>mp;
        int cur_sum = 0;
        int ans = 0;
        int n = arr.size();
        for(int i=0; i<n;i++){
            cur_sum += arr[i];
            if(cur_sum == 0) ans = i+1;
            if(mp.find(cur_sum) != mp.end()) ans = max(ans, i - mp[cur_sum] + 1);
            else mp[cur_sum] = i + 1;
        }
        return ans;


}