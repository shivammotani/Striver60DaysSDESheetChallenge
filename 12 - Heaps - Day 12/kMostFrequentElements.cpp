vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
        // Write your code here.
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto a : arr)
                mp[a]++;
        priority_queue<pair<int, int>> pq;
        for (auto &a : mp)
        {
                pq.push({a.second, a.first});
        }

        while (k--)
        {
                auto temp = pq.top();
                ans.push_back(temp.second);
                pq.pop();
        }

        return ans;
}