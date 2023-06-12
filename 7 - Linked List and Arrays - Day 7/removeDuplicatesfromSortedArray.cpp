int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int ans = 1;
	int el = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]!= el){
			ans++;
			el = arr[i];
		}
	}
	return ans;
}