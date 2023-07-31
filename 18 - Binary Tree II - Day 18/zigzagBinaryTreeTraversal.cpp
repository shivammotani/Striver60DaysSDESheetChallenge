#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
        //    Write your code here.
        bool leftToRight = false;
        queue<TreeNode<int> *> q;
        vector<int> ans;
        if (root == NULL)
                return ans;
        q.push(root);
        while (!q.empty())
        {
                int sz = q.size();
                vector<int> t;
                while (sz--)
                {
                        TreeNode<int> *temp = q.front();
                        q.pop();
                        if (temp->left)
                                q.push(temp->left);
                        if (temp->right)
                                q.push(temp->right);
                        t.push_back(temp->data);
                }
                if (!leftToRight)
                        ans.insert(ans.end(), t.begin(), t.end());
                else
                {
                        reverse(t.begin(), t.end());
                        ans.insert(ans.end(), t.begin(), t.end());
                }
                leftToRight = !leftToRight;
        }
        return ans;
}