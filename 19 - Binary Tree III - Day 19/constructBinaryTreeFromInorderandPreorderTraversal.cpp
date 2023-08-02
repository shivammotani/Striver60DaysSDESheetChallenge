#include <bits/stdc++.h>
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
TreeNode<int> *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
        if (preStart > preEnd || inStart > inEnd)
                return NULL;
        TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);

        int rootInorderindex = mp[root->data];
        int numsonLeft = rootInorderindex - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsonLeft, inorder, inStart, rootInorderindex - 1, mp);
        root->right = buildTree(preorder, preStart + numsonLeft + 1, preEnd, inorder, rootInorderindex + 1, inEnd, mp);
        return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
        //    Write your code here
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
                mp[inorder[i]] = i;

        TreeNode<int> *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
}