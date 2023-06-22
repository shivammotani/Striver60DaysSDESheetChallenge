#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> ans;
    stack<pair<int,int>>st;
    st.push({price[0],1});
    ans.push_back(1);
    // 

    for(int i=1; i<price.size(); i++){
        if(price[i] == st.top().first) {
            ans.push_back(st.top().second + 1);
            st.pop();
            st.push({price[i],ans[i]});
        }
        else if(price[i] < st.top().first){
            ans.push_back(1);
            st.push({price[i],1});
        }
        else{
            int cnt = st.top().second;
            int idx = i-cnt-1;
            while(idx >=0 && price[i] >= price[idx--]) cnt++;
            ans.push_back(cnt + 1);
            st.push({price[i],ans[i]});
        }
    }
    return ans;
}