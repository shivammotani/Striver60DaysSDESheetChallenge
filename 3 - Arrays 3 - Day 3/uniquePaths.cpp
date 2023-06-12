int uniquePaths(int m, int n) {
	// Write your code here.
	int totalPath = m+n-2;
	int permutation = 0;
	int ans = 1;
	if(m < n) permutation = m-1;
	else permutation = n-1;

	for(int i=0; i<permutation; i++){
		ans *= totalPath - i;
		ans /= i+1;
	}
	return ans;
}