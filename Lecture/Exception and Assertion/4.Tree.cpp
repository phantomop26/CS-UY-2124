/*
  4.Tree
    - How can we use recursion on a binary tree if empty trees are permitted?
    - And how if they are not?
    - consider functions treeSum and treeMax
    - others? treeSumLeaves, treeReverse, ...
  jbs
 */
#include <iostream>   // cout
#include <algorithm>  // max, min
using namespace std;

struct TNode {
    TNode(int val, TNode* left = nullptr, TNode* right = nullptr)  : data(val), left(left), right(right) {}
    int data;
    TNode* left;
    TNode* right;
};

int treeSum(TNode* root) {
    if (root == nullptr) 0;
    return root->data + treeSum(root->left) + treeSum(root->right);
}

// int treeMin(TNode* root) {
//     if (root == nullptr) INY_MIN;
//     return min(root->data,  min(treeMin(root->left), treeMin(root->right)));
// }

// int treeMin(TNode* root) {
//     //    return min(root->data,  min(treeMin(root->left), treeMin(root->right)));
//     if (root->left == nullptr && root->right == nullptr) return root->data;
//     if (root->left == nullptr) return min(root->data, treeMin(root->right));
//     if (root->right == nullptr) return min(root->data, treeMin(root->left));
//     // both not null
//     return min(root->data,  min(treeMin(root->left), treeMin(root->right)))
    
// }

int treeMin(TNode* root) {
    //    return min(root->data,  min(treeMin(root->left), treeMin(root->right)));

    int result = root->data;
    if (root->left != nullptr) result = min(result, treeMin(root->left));
    if (root->right != nullptr) result = min(result, treeMin(root->right));
    return result;
}

int main() {
    TNode* tree = new TNode(1);
    tree->left = new TNode(2);
    tree->right = new TNode(3);
    tree->left->left = new TNode(4);
    tree->left->right = new TNode(5);

    TNode* tree2 = new TNode(-1);
    tree2->left = new TNode(-2);
    tree2->right = new TNode(-3);
    tree2->left->left = new TNode(-4);
    tree2->left->right = new TNode(-5);

    cout << treeSum(tree) << ' ' << treeSum(tree2) << endl;
    cout << treeMin(tree) << ' ' << treeMin(tree2) << endl;
}
