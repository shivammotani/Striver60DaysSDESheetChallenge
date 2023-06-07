pair<int,int> missingAndRepeating(vector<int> &arr, long long n)
{
	// Write your code here 
	long long sumOfFirstN = (n*(n+1))/2;
	long long sumOfFirstN2 = (n*(n+1)*(2*n+1))/6;
	long long sm1 = 0;
	long long sm2 = 0;
	for(int i=0; i<n; i++){
		sm1 += arr[i];
		sm2 += (long long)arr[i] * (long long)arr[i];
	}

	long long val1 = sm1 - sumOfFirstN; 
	long long val2 = sm2 - sumOfFirstN2;
	val2 = val2/val1;
	long long x = (val1 + val2)/2;
	long long y = x-val1;
	pair<int, int> ans((int)y, (int)x);
	return ans;
}
