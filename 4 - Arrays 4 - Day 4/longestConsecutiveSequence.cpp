int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {

// Write your code here.

    int ans=1;
    unordered_map<int,int>mp;
    for(auto a:arr) mp[a]++;

    for(int i=0; i<n; i++){
        int cnt=1;
        if(mp.find(arr[i]-1) == mp.end()){
            int val = arr[i];
            while(mp.find(++val) != mp.end()) cnt++;
        }
        ans = max(ans,cnt);

    }
    return ans;
}