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
    void InOrderTrav(TreeNode* root, int& count, int& k, int &ans){
        if(!root) return;
        if(root->left) InOrderTrav(root->left, count, k, ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        if(root->right) InOrderTrav(root->right, count, k, ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root->left && !root->right) return root->val;
        int count = 0;
        int ans = 0;
        // sort(answer.begin(), answer.end());
        InOrderTrav(root, count, k, ans);

        return ans;
    }
};