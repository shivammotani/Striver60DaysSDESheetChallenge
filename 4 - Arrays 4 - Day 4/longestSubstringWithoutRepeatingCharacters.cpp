#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans = 0;
    vector<int>mp(256,-1);
    int left=0,right=0;
    int n = input.length();

    while(right<n){
        if(mp[input[right]] != -1){
            left = max(left, mp[input[right]]+1);
        }
        mp[input[right]] = right;
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;

}