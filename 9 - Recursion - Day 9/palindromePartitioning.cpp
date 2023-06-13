#include <bits/stdc++.h> 

bool isPalin(string &s, int start, int end){
    while(start<=end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}


void solve(vector<vector<string>> &ans, vector<string> &temp, string &s,int i){
	if (i == s.size()) {
		ans.push_back(temp);
		return;
	}

	for(int ind = i; ind<s.size(); ind++){
        if(isPalin(s,i,ind)){
            temp.push_back(s.substr(i, ind-i+1));
            solve(ans, temp, s,ind+1);
            temp.pop_back();
        }
		
	}

}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
	vector<string> temp;
	solve(ans, temp, s,0);
	return ans;
}