#include <bits/stdc++.h>

int solve(priority_queue<int> &small, priority_queue<int, vector<int>, greater<int>> &large, int num)
{

        if (small.size() == 0)
                small.push(num);
        else if (small.size() > large.size())
        {
                if (num < small.top())
                {
                        large.push(small.top());
                        small.pop();
                        small.push(num);
                }
                else
                        large.push(num);
        }
        else
        {
                if (num < small.top())
                {
                        small.push(num);
                }
                else
                {
                        large.push(num);
                        small.push(large.top());
                        large.pop();
                }
        }

        if (small.size() == large.size())
                return (small.top() + large.top()) / 2;
        return small.top();
}

void findMedian(int *arr, int n)
{
        // Write your code here
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> large;
        for (int i = 0; i < n; i++)
                cout << solve(small, large, arr[i]) << " ";
}