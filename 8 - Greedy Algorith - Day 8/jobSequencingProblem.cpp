#include <bits/stdc++.h> 

bool mycmp(vector<int> v1, vector<int> v2){
    return v1[1] > v2[1];
}


int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int rows = jobs.size();
    sort(jobs.begin(), jobs.end(), mycmp);

    vector<int> store(3001, -1);
    int ans = 0;
    for(int i=0; i<rows; i++){
        if(store[jobs[i][0]] == -1) store[jobs[i][0]] = jobs[i][1];
        else{
            int id = jobs[i][0] - 1;
            while(id>0){
              if (store[id] == -1) {
                store[id] = jobs[i][1];
                break;
              }
              id--;
            }
        }
    }
    for(int i=0; i<3002; i++) {
        if(store[i] != -1) ans+= store[i];
    }
    return ans;
    
}
