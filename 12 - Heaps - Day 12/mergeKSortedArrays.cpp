#include <bits/stdc++.h>

struct data
{
        int val;
        int idx;
        int arrNum;
};

struct customComp
{
        bool operator()(data d1, data d2) { return d1.val > d2.val; }
};

vector<int>
mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
        // Write your code here.
        vector<int> ans;
        priority_queue<data, vector<data>, customComp> pq;
        for (int i = 0; i < k; i++)
        {
                struct data d1 = {kArrays[i][0], 0, i};
                pq.push(d1);
        }
        while (!pq.empty())
        {
                auto temp = pq.top();
                pq.pop();
                ans.push_back(temp.val);
                int idx = temp.idx;
                int arrNum = temp.arrNum;
                if (idx + 1 < kArrays[arrNum].size())
                {
                        struct data d1 = {kArrays[arrNum][idx + 1], idx + 1, arrNum};
                        pq.push(d1);
                }
        }
        return ans;
}
