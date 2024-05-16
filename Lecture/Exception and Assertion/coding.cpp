#include <iostream>
using namespace std;


int maxDepth(TreeNode* root){
    if(root == null) return 0;
    int lh = maxDepth(TreeNode* root->left);
    int rh = maxDepth(TreeNode* root->right);
    return 1+ max(lh,rh);
}

