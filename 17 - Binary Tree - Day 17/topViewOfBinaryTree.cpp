#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root)
{
        // Write your code here.
        map<int, int> nodes;
        vector<int> ans;
        if (root == NULL)
                return ans;
        queue<pair<TreeNode<int> *, int>> todo;
        todo.push({root, 0});
        while (!todo.empty())
        {
                auto p = todo.front();
                todo.pop();
                TreeNode<int> *first = p.first;
                int vertical = p.second;
                if (nodes.find(vertical) == nodes.end())
                        nodes[vertical] = first->val;
                if (first->left)
                        todo.push({first->left, vertical - 1});
                if (first->right)
                        todo.push({first->right, vertical + 1});
        }

        for (auto node : nodes)
        {
                ans.push_back(node.second);
        }

        return ans;
}