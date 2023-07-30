#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root)
{

        // Write your code here.
        map<int, int> nodes;
        queue<pair<BinaryTreeNode<int> *, int>> todo;
        todo.push({root, 0});
        while (!todo.empty())
        {
                auto p = todo.front();
                todo.pop();
                BinaryTreeNode<int> *first = p.first;
                int vertical = p.second;
                nodes[vertical] = first->data;
                if (first->left)
                        todo.push({first->left, vertical - 1});
                if (first->right)
                        todo.push({first->right, vertical + 1});
        }

        vector<int> ans;

        for (auto node : nodes)
        {
                ans.push_back(node.second);
        }

        return ans;
}
