#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
        return true;
    if (min != NULL && root->data <= min->data)
        return false;
    if (max != NULL && root->data >= max->data)
        return false;

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}

int main()
{
    Node *root = NULL,*min=NULL,*max=NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 2);
    insertBST(root, 4);
    
    cout<<isBST(root,min,max);
}