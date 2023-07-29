#include <bits/stdc++.h>
using namespace std;

void insertInHeap(vector<int> &ans, int val)
{
        ans.push_back(val);
        int idx = ans.size() - 1;

        while (idx > 0)
        {
                int parent = (idx - 1) / 2;
                if (ans[parent] > ans[idx])
                {
                        swap(ans[parent], ans[idx]);
                        idx = parent;
                }
                else
                        break;
        }
        return;
}

int deleteFromHeap(vector<int> &ans)
{
        int returnedVal = ans[0];
        if (ans.size() == 1)
        {
                ans.pop_back();
                return returnedVal;
        }
        ans[0] = ans[ans.size() - 1];
        ans.pop_back();
        int idx = 0;
        while (idx < ans.size())
        {
                int leftChild = 2 * idx + 1;
                int rightChild = 2 * idx + 2;
                int mini = idx;
                if (leftChild < ans.size() && ans[mini] > ans[leftChild])
                {
                        mini = leftChild;
                }
                if (rightChild < ans.size() && ans[mini] > ans[rightChild])
                {
                        mini = rightChild;
                }
                if (mini != idx)
                {
                        swap(ans[idx], ans[mini]);
                        idx = mini;
                }
                else
                        break;
        }
        return returnedVal;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{
        // Write your code here.
        vector<int> ans;
        vector<int> finAns;
        for (int i = 0; i < n; i++)
        {
                // cout << "j";
                if (q[i][0] == 0)
                        insertInHeap(ans, q[i][1]);
                else
                        finAns.push_back(deleteFromHeap(ans));
        }

        return finAns;
}
