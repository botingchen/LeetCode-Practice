/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        else if(!root->left && !root->right) return 0;
        else if(!root->left) return sumOfLeftLeaves(root->right);
        else if(!root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};