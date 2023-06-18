#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int>st;
    vector<int>ans(n,0);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(st.empty()){
            ans[i] = -1;
            st.push(arr[i]);
        }
        else{
            ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}