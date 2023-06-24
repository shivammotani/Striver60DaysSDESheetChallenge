#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int>left(n,-1);
    vector<int>right(n,n);
    vector<int>ans(n,INT_MIN);
    stack<int>s;

    for(int i=0; i<n; i++){
        
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) left[i] = s.top();
        s.push(i);
    }

    s = stack<int>();

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) right[i] = s.top();
        s.push(i);
    }


    for(int i=0; i<n; i++){
        int size = right[i] - left[i] - 2;
        ans[size] = max(ans[size], a[i]);
    }
    for(int i=n-2; i>=0; i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;

}