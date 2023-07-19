#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[],int st,int en,int curr)
{
    for (int  i = st; i <= en; i++)
    {
        if(inorder[i]==curr)
        return i;
    }

    return -1;
    
}

// Node* buildTreepre(int preorder[],int inorder[],int st,int en)
// {
//     static int idx=0;
//     if(st>en)
//     return NULL;

//     int curr = preorder[idx];
//     idx++;

//     Node* node = new Node(curr);
//     if(st==en)
//     return node;

//     int pos = search(inorder,st,en,curr);
//     node->left = buildTreepre(preorder,inorder,st,pos-1);
//     node->right = buildTreepre(preorder,inorder,pos+1,en);
//     return node;
// }

Node* buildTreepost(int postorder[],int inorder[],int st,int en)
{
    static int idx=4;
    if(st>en)
    return NULL;

    int curr = postorder[idx];
    idx--;

    Node* post = new Node(curr);
    if(st==en)
    return post;

    int pos = search(inorder,st,en,curr);
    post->right = buildTreepost(postorder,inorder,pos+1,en);
    post->left = buildTreepost(postorder,inorder,st,pos-1);
    return post;
}

void inorderprint(Node* root)
{
    if(root==NULL)
    return;
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}


int main()
{
    // int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    int postorder[]={4,2,5,3,1};

    // Node* rootPre = buildTreepre(preorder,inorder,0,4);
    // inorderprint(rootPre);
    // cout<<endl;

    Node* rootpost = buildTreepost(postorder,inorder,0,4);
    inorderprint(rootpost);
}