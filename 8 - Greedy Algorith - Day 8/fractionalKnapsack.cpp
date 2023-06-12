#include <bits/stdc++.h> 

static bool mycmp(pair<int, int> a, pair<int, int> b){
    double a1 = (double)a.second/a.first;
    double a2 = (double)b.second/b.first;
    return a1 > a2;
}


double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double ans = 0;
    sort(items.begin(), items.end(), mycmp);
    for(int i=0; i<n; i++){
        if(items[i].first <= w){
            ans += items[i].second;
            w -= items[i].first;
        }
        else{
            ans += ((double)w/items[i].first)*items[i].second;
            break;
        }
    }
    return ans;
}