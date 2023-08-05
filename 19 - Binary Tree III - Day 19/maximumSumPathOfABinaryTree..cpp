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
int calc(TreeNode<int> *root, int &ans)
{
        if (root == NULL)
                return 0;

        int left = max(0, calc(root->left, ans));
        int right = max(0, calc(root->right, ans));
        ans = max(ans, root->data + left + right);
        return root->data + max(left, right);
}
int maxPathSum(TreeNode<int> *root)
{
        // Write your code here
        int ans = -99999999;
        calc(root, ans);
        return ans;
}