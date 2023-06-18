#include <bits/stdc++.h> 

bool minTime(vector<int> &time, long long val, int c){
	long long cnt = 0, sm = 0;
	for(int i=0; i<time.size(); i++){
		if(time[i] > val) return false;
		if(sm+time[i] > val){
			cnt++;
			sm = time[i];
		}
		else sm += time[i];
	}

	if(cnt < c) return true;
	return false;
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long low = 1;
	long long high = 0;
	//to find minimum value and sum of all pages
	for (int i = 0; i < time.size(); i++) {
		high = high + time[i];
	}

	while(low<=high){
		long long mid = low+high >> 1;
		if(minTime(time,mid,n)) high = mid-1;
		else low = mid+1;
	}
	return low;
}