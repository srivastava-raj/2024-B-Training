#include<iostream>
#include<stack>
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

void swap(Node* currLevel,Node* nextLevel){
     Node* temp = currLevel;
     currLevel= nextLevel;
     nextLevel = temp;

}

void zigZagTraversal(Node* root){
    if(root==NULL)
        return;
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);
    while(!currLevel.empty()){
        Node*temp = currLevel.top();
        currLevel.pop();
        if(temp){
            cout<<(*temp).data<<" ";
            if(leftToRight){
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else{
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }

    }
}

int main(){
    Node* root=NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    zigZagTraversal(root);
}