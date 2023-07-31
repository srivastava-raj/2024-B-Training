#include <iostream>
using namespace std;
 
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool isValidBST(TreeNode* root) {
    TreeNode* curr = root;
    TreeNode* prev = NULL;
     
    while (curr != NULL) {
        if (curr->left == NULL) { // case 1: no left child
            // process the current node
            if (prev != NULL && prev->val >= curr->val)
                return false;
            prev = curr;
            curr = curr->right;
        }
        else { // case 2: has a left child
            // find the inorder predecessor
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;
             
            if (pred->right == NULL) { // make threaded link
                pred->right = curr;
                curr = curr->left;
            }
            else { // remove threaded link
                pred->right = NULL;
                // process the current node
                if (prev != NULL && prev->val >= curr->val)
                    return false;
                prev = curr;
                curr = curr->right;
            }
        }
    }
     
    return true; // binary tree is a valid BST
}
// Driver Code
int main() {
    // create the binary tree from the example
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
     
    // check if the binary tree is a valid BST
    if (isValidBST(root))
        cout << "The binary tree is a valid BST." << endl;
    else
        cout << "The binary tree is not a valid BST." << endl;
     
    return 0;
}