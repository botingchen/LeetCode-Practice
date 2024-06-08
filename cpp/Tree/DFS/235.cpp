/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // void ancestor_list(TreeNode* root, TreeNode* p, vector)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int maxv = max(p->val, q->val);
        int minv = min(p->val, q->val);
        while(root){
            if(root->val <= maxv && root->val >= minv) return root;
            else if(root->val > maxv) root = root->left;
            else if(root->val < minv) root = root->right;
        }
        return NULL;
    }
};