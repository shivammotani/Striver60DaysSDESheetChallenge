#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
        // Write your code here.
        int ans = 0;
        if (root == NULL)
                return ans;
        queue<TreeNode<int> *> q;
        q.push(root);
        ans = 1;
        while (!q.empty())
        {
                int sz = q.size();
                for (int i = 0; i < sz; i++)
                {
                        TreeNode<int> *temp = q.front();
                        q.pop();
                        if (temp->left)
                                q.push(temp->left);
                        if (temp->right)
                                q.push(temp->right);
                }
                int a = q.size();
                ans = max(ans, a);
        }
        return ans;
}