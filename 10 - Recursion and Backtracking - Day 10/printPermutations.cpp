#include <bits/stdc++.h> 

void solve(string &s,vector<string> &ans, int ind){
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        swap(s[i], s[ind]);
        solve(s, ans,ind+1);
        swap(s[i], s[ind]);
    }

}


vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    solve(s, ans,0);
    return ans;
}