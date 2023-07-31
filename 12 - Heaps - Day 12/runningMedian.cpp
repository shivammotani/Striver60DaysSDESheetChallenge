#include <bits/stdc++.h>

int solve(priority_queue<int> &smallerOnLeft, priority_queue<int, vector<int>, greater<int>> &largestOnRight, int num)
{

        if (smallerOnLeft.size() == 0)
                smallerOnLeft.push(num);
        else if (smallerOnLeft.size() > largestOnRight.size())
        {
                if (num < smallerOnLeft.top())
                {
                        largestOnRight.push(smallerOnLeft.top());
                        smallerOnLeft.pop();
                        smallerOnLeft.push(num);
                }
                else
                        largestOnRight.push(num);
        }
        else
        {
                if (num < smallerOnLeft.top())
                {
                        smallerOnLeft.push(num);
                }
                else
                {
                        largestOnRight.push(num);
                        smallerOnLeft.push(largestOnRight.top());
                        largestOnRight.pop();
                }
        }

        if (smallerOnLeft.size() == largestOnRight.size())
                return (smallerOnLeft.top() + largestOnRight.top()) / 2;
        return smallerOnLeft.top();
}

void findMedian(int *arr, int n)
{
        // Write your code here
        priority_queue<int> smallerOnLeft;
        priority_queue<int, vector<int>, greater<int>> largestOnRight;
        for (int i = 0; i < n; i++)
                cout << solve(smallerOnLeft, largestOnRight, arr[i]) << " ";
}