#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

// int height(Node *root)
// {
//     if(root==NULL)
//     return 0;
//     return max(height(root->left),height(root->right))+1;
// }

// bool isBalanced(Node *root)
// {
//     if(root == NULL)
//     return true;

//     if(isBalanced(root->left)==false)
//     return false;
//     if(isBalanced(root->right)==false)
//     return false;

//     int lh=height(root->left);
//     int rh=height(root->right);

//     if(abs(lh-rh)<=1)
//     return true;

//     else
//     return false;

// }

bool isBalancedOptimized(Node *root,int *height)
{
    if(root = NULL)
    return true;
    int lh=0;
    int rh=0;
    if(isBalancedOptimized(root->left,&lh)==false)
    return false;
    if(isBalancedOptimized(root->right, &rh)==false)
    return false;

    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height=0;
    cout<<isBalancedOptimized(root,&height);
    // cout<<"Tree is balanced";
    // else
    // cout<<"tree is not balanced";

}
