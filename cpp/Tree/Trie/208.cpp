class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool isword;
    TrieNode(){
        isword = false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur_node = root;
        for(auto c: word){
            if(cur_node->children.find(c) == cur_node->children.end()){
                cur_node->children[c] = new TrieNode();
            }
            cur_node = cur_node->children[c];
        }
        cur_node->isword = true;
    }
    
    bool search(string word) {
        TrieNode* cur_node = root;
        for(auto c: word){
            if(cur_node->children.find(c) == cur_node->children.end()) return false;
            cur_node = cur_node->children[c];
        }
        return cur_node->isword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;
        for(auto c: prefix){
            if(cur_node->children.find(c) == cur_node->children.end()) return false;
            cur_node = cur_node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */