#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node* root,int val){
    if(root==NULL)
        return new Node(val);
    if(val < root->data)
        root->left = insertBST(root->left,val);
    else
        root->right = insertBST(root->right,val);
        
    return root;
}

Node* searchInBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key)
        return root;
    if(root->data > key)
        return searchInBST(root->left,key);
    else
    return searchInBST(root->right,key);
}

void inorderprint(Node* root)
{
    if(root == NULL)
        return ;
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);

}

int main(){
    Node* root= NULL;
    root = insertBST(root,5);
    insertBST(root,3);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,2);
    insertBST(root,8);
    inorderprint(root);
    if(searchInBST(root,2)!=NULL)
        cout<<"Element Found";
    else cout<<"Element not found";
}