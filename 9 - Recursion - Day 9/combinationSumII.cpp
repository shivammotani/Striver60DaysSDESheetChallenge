#include<bits/stdc++.h>
void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr,int i, int n, int target){
	if (target == 0) {
		ans.push_back(temp);
		return;
	}

	for(int ind = i; ind<n; ind++){
		if (ind > i and arr[ind] == arr[ind - 1])	continue; 
        if(arr[ind] > target) break;
		temp.push_back(arr[ind]);
		solve(ans, temp, arr,ind+1, n, target-arr[ind]);
		temp.pop_back();
	}

}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> temp;
	sort(arr.begin(), arr.end());
	solve(ans, temp, arr,0, n, target);
	return ans;
}
