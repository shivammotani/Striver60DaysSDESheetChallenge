#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<pair<int, int>> meet;
    for(int i=0; i<n; i++){
        meet.push_back({finish[i], start[i]});
    }   
    sort(meet.begin(), meet.end());
    int v = meet[0].first;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(meet[i].second >= v){
            ans++;
            v = meet[i].first;
        }
    }
    return ans;
}