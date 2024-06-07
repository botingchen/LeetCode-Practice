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
    bool sol(TreeNode* root, long long int max, long long int min){
        if(!root) return true;
        if(root->val < max && root->val > min ) return sol(root->left, root->val, min) && sol(root->right, max, root->val);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long int max = 10000000000;
        long long int min = -10000000000;
        return sol(root, max, min);
        
    }
};