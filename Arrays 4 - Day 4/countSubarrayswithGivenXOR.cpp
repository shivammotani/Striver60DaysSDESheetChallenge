#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int xr = 0,cnt=0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int i=0; i<arr.size(); i++){
        xr ^= arr[i];
        int temp = x^xr;
        cnt += mp[temp];
        mp[xr]++;
    }
    return cnt;
}