/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur_node, unordered_map<Node*, Node*>& mymap){
        vector<Node*> neighbor;
        Node* new_node = new Node(cur_node->val);
        mymap[cur_node] = new_node;
        for(auto i : cur_node->neighbors){
            if(mymap.find(i) == mymap.end()) new_node->neighbors.push_back(dfs(i, mymap));
            else{
                new_node->neighbors.push_back(mymap[i]);
            }
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mymap;
        if(!node) return node;
        return dfs(node, mymap);
    }
};