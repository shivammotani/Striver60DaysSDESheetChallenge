/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int dfs(TreeNode<int> *root, int &ans)
{
        if (root == NULL)
                return 0;
        int lh = dfs(root->left, ans);
        int rh = dfs(root->right, ans);
        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
        // Write Your Code Here.
        if (root == NULL)
                return -1;
        int ans = 0;
        dfs(root, ans);
        return ans;
}
