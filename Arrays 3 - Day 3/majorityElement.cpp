int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int,int> ans;
	for(int i=0; i<n; i++) ans[arr[i]]++;
	for(int i=0; i<n; i++) if(ans[arr[i]] > (n/2)) return arr[i];
	return -1;
}


OR 


int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int el = arr[0], cnt = 1;
	for(int i=1; i<n; i++){
		if(arr[i] == el) cnt++;
		else cnt--;
		if(cnt == 0){
			el = arr[i];r
			cnt = 1;
		}
	} 
	int cnt1 = 0;
	for(int i=0; i<n; i++) if(el == arr[i]) cnt1++;
	if(cnt1 > (n/2)) return el;
	return -1;
}