/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
int check(Node *root)
{
        if (root == NULL)
                return 0;

        int left = check(root->left);
        int right = check(root->right);

        if ((root->left == NULL && root->right == NULL) || root->data == (left + right))
        {
                int ans = root->data;
                return ans;
        }
        return -1;
}

bool isParentSum(Node *root)
{
        // Write your code here.
        if (check(root) == -1)
                return false;
        return true;
}