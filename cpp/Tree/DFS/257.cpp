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
//Iterative
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return {to_string(root->val)};
        stack<TreeNode*> mystack;
        vector<string> ans;
        unordered_map<TreeNode*, string> mymap;
        mystack.push(root);
        string tmp = "";
        while(!mystack.empty()){
            TreeNode* cur_node = mystack.top();
            if(cur_node == root) tmp += to_string(cur_node->val);
            else tmp = mymap[cur_node] + "->" + to_string(cur_node->val);
            mystack.pop();
            if(cur_node->right){
                mystack.push(cur_node->right);
                mymap[cur_node->right] = tmp;
            }
            if(cur_node->left){
                mystack.push(cur_node->left);
                mymap[cur_node->left] = tmp;
            }
            if(!cur_node->left && !cur_node->right) ans.push_back(tmp);
        }
        return ans;
    }
};

//Recursive
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>* vec){
        if(!root) return;
        else if(!root->left && !root->right){
            vec->push_back(path + "->" + to_string(root->val));
            return;
        }
        dfs(root->left, path+"->"+to_string(root->val), vec);
        dfs(root->right, path+"->"+to_string(root->val),vec);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return {to_string(root->val)};
        vector<string> ans;
        string path = "";
        path+=to_string(root->val);
        dfs(root->left, path, &ans);
        dfs(root->right, path, &ans);
        return ans;
    }
};