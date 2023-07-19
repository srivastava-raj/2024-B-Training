#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};


Node* insertBST(Node* root,int val)
{
    if(root==NULL)
        return new Node(val);
    if(val < root->data)
        root->left = insertBST(root->left,val);
    else
        root->right = insertBST(root->right,val);
    return root;
}

Info largestBSTinBT(Node* root){
    if(root == NULL)
        return {0,INT_MIN,INT_MAX,0,true};
    if(root->left == NULL && root->right == NULL)
        return {1,root->data,root->data,1,true};
    
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min, min(rightInfo.min,root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max,root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;
    return curr;

}


int main(){
    Node* root=NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,6);
    insertBST(root,2);
    insertBST(root,4);
    Info a;
    a = largestBSTinBT(root);
    cout<<"max size"<<a.ans<<endl;
    
}