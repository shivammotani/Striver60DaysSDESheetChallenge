#include <bits/stdc++.h> 

bool focus(vector<int> &positions, int val, int c){
	int cnt = 1, lastIndex = 0;
	for(int i=1; i<positions.size(); i++){
		if(positions[i] - positions[lastIndex] >= val){
			cnt++;
			lastIndex = i;
		}
		if(cnt >= c) return true;
	}
	return (cnt >= c);
}

int chessTournament(vector<int> &positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int low = 1;
	int high = positions[n-1];
	while(low<=high){
		int mid = low+high >> 1;
		if(focus(positions,mid,c)) low = mid+1;
		else high = mid-1;
	}
	return low-1;
}