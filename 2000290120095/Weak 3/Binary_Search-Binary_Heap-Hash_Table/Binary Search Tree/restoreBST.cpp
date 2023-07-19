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

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev){
    if(root == NULL)
        return;
    calcPointers (root->left,first,mid,last,prev);
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
           
        }
        else
            *last  = root;
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(Node* root){
    Node *first,*mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else
    {
        swap(&(first->data),(&mid->data));
    }

}

void inorder(Node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);
    inorder(root);
    restoreBST(root);
    cout<<endl;
    inorder(root);

}