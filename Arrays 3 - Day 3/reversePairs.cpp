void merge(vector<int> &arr, int low, int mid, int high) {
	int left = low;
	int right = mid+1;
	vector<int>temp;
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
		else temp.push_back(arr[right++]);
	}

	while(left <= mid) temp.push_back(arr[left++]);
	while(right <= high) temp.push_back(arr[right++]);

	for(int i=low; i<=high; i++) arr[i] = temp[i-low];
}

int countpairs(vector<int> &arr, int low, int mid, int high) {
	int cnt=0;
	int right = mid+1;
	for(int i=low; i<=mid; i++){
		while(right<=high && arr[i] > 2*arr[right]) right++;
		cnt += right-(mid+1);
	}
	return cnt;
}

int mergemain(vector<int> &arr, int low, int high){
	int cnt = 0;
	if(low >= high) return cnt;
	int mid= (low+high) >> 1;
	cnt += mergemain(arr, low, mid);
	cnt += mergemain(arr,mid+1,high);
	cnt += countpairs(arr,low,mid,high);
	merge(arr,low,mid,high);
	return cnt;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergemain(arr,0,n-1);
}