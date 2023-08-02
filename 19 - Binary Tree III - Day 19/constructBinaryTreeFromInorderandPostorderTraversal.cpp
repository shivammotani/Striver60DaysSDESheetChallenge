#include <bits/stdc++.h>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
                {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
TreeNode<int> *buildTree(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
        if (postStart > postEnd || inStart > inEnd)
                return NULL;
        TreeNode<int> *root = new TreeNode<int>(postOrder[postEnd]);

        int rootInorderindex = mp[root->data];
        int numsonLeft = rootInorderindex - inStart;

        root->left = buildTree(postOrder, postStart, postStart + numsonLeft - 1, inorder, inStart, rootInorderindex - 1, mp);
        root->right = buildTree(postOrder, postStart + numsonLeft, postEnd - 1, inorder, rootInorderindex + 1, inEnd, mp);
        return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inorder)
{
        // Write your code here.
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
                mp[inorder[i]] = i;

        TreeNode<int> *root = buildTree(postOrder, 0, postOrder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
}
