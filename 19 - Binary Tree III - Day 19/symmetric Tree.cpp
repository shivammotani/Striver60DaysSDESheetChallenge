#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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

***************/
bool isSymmetricHelp(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
        if (left == NULL || right == NULL)
                return left == right;
        if (left->data != right->data)
                return false;
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
        // Write your code here
        return root == NULL || isSymmetricHelp(root->left, root->right);
}