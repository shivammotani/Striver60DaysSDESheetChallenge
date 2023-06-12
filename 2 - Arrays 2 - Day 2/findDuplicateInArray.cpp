int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int,int> mp;
	for(auto a: arr){
		if(mp.find(a) != mp.end()) return a;
		mp[a]++;
	}
}