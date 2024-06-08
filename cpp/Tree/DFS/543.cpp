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
    int height(TreeNode *root, int & answer){
        if(!root) return 0;
        int left = height(root->left, answer);
        int right = height(root->right, answer);
        answer = max(answer, left+right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int answer = 0;
        height(root, answer);
        return answer;
    }
};