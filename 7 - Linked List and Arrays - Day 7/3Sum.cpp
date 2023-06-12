#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i=0; i<n-2; i++){
		if((i == 0) || (i>0 && arr[i] != arr[i-1])){
			int left = i+1, right = n-1;
			int target = K-arr[i];
			while(left<right){
				// cout << arr[i] << "-" << arr[left] << "-" << arr[right] << "-" << target << endl;
				if(target == (arr[left] + arr[right])){
					vector<int>temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[left]);
					temp.push_back(arr[right]);
					ans.push_back(temp);

					while(left < right and arr[left] == arr[left+1]) left++;
					while(left < right and arr[right] == arr[right-1]) right--;
					left++;
					right--;
				}
				else if(target > (arr[left] + arr[right])) left++;
				else right--;
			}
		}
	
	}
	return ans;
}