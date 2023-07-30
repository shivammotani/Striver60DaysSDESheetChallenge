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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
        //    Write your code here.
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode<int> *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
                auto p = todo.front();
                todo.pop();
                TreeNode<int> *first = p.first;
                int vertical = p.second.first;
                int level = p.second.second;
                nodes[vertical][level].push_back(first->data);
                if (first->left)
                        todo.push({first->left, {vertical - 1, level + 1}});
                if (first->right)
                        todo.push({first->right, {vertical + 1, level + 1}});
        }

        vector<int> ans;
        for (auto node : nodes)
        {
                for (auto n : node.second)
                        ans.insert(ans.end(), n.second.begin(), n.second.end());
        }

        return ans;
}