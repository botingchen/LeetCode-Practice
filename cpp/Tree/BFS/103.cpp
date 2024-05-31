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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode* >q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            vector<int> vec;
            size_t size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* cur_node = q.front();
                q.pop();
                if(cur_node->left) q.push(cur_node->left);
                if(cur_node->right) q.push(cur_node->right);
                vec.push_back(cur_node->val);
            }
            if((cnt%2)) reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            cnt++;
        }
        return ans;
    }
};