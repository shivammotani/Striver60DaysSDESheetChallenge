#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

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
int dfs(BinaryTreeNode<int> *root)
{
        if (root == NULL)
                return 0;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        if (lh == -1 || rh == -1)
                return -1;
        if (abs(lh - rh) > 1)
                return -1;
        return 1 + max(lh, rh);
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
        // Write your code here.
        if (root == NULL)
                return true;
        int ans = dfs(root);
        if (ans == -1)
                return false;
        return true;
}