#include <bits/stdc++.h> 


void solve(vector<string> &ans, vector<string> &dictionary, map<string,int> &mp, string &s, string &temp, int idx){
    if(idx == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=idx; i<s.size(); i++){
        string tmp = s.substr(idx, i - idx + 1);
        if(mp[tmp] >= 1){
            int ln = temp.size();
            temp += tmp + " ";
            solve(ans,dictionary,mp,s,temp,i+1);
            temp.erase(ln);
        }  
    }
}



vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    map<string, int> mp;
    for(int i = 0; i < dictionary.size(); i++){
        mp[dictionary[i]]++;
    }
    string temp = "";
    solve(ans,dictionary,mp,s,temp,0);
    return ans;

}




