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
int dfs(TreeNode<int> *root)
{
        if (root == NULL)
                return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
}
int maxDepth(TreeNode<int> *root)
{
        // Write your code here.
        if (root == NULL)
                return -1;
        int ans = dfs(root);
        return ans - 1;
}