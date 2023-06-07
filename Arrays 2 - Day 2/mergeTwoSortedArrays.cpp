vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int len = m+n;
	int gap = (len/2) + (len%2);
	while(gap > 0){
		int left=0, right=left + gap;
		while(right < len){
			// arr1 and arr2
			if(left <m && right >= m){
				swapGreater(arr1,arr2,left,right-m);
			}
			//arr2 and arr2
			else if(left>=m){
				swapGreater(arr2,arr2,left-m,right-m);
			}
			else{
				swapGreater(arr1,arr1,left,right);
			}
			left++;
			right++;
		}
		if(gap == 1) break;
		gap = (gap/2) + (gap%2);
	}
	for(int i=0; i<n; i++) arr1[m+i] = arr2[i];
	return arr1;
}