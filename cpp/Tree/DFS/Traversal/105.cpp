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
    TreeNode* sol(vector<int>preorder, vector<int> inorder, int start, int end, int &index){
        if(start > end) return NULL;
        int root_val = preorder[index];
        TreeNode* root = new TreeNode(root_val);
        index++;
        int root_index_in_inorder = start;
        for(;root_index_in_inorder<=end; root_index_in_inorder++){
            if(inorder[root_index_in_inorder] == root_val){
                break;
            }
        }
        // int root_index_in_inorder = mymap[root_val];
        root->left = sol(preorder, inorder, start, root_index_in_inorder-1, index);
        root->right = sol(preorder, inorder, root_index_in_inorder+1, end, index);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return sol(preorder, inorder, 0, preorder.size()-1, index);
    }
};