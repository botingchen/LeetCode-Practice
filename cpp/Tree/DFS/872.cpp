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
    void traverse(list<int>& a, TreeNode* root){
        if(root == NULL) return;
        else if(!root->left && !root->right) a.push_back(root->val);
        else{
            // root = !root->left?root->right:root->left;
            traverse(a, root->left);
            traverse(a, root->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list<int> result1;
        list<int> result2;
        traverse(result1, root1);
        traverse(result2, root2);
        return result1 == result2;
    }
};