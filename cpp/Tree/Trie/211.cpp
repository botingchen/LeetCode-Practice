class TrieNode{
public:
    unordered_map<char ,TrieNode*> children;
    bool isword = false;
    TrieNode(){
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur_node = root;
        for(auto i : word){
            if(cur_node->children.find(i) == cur_node->children.end()){
                TrieNode* child_node = new TrieNode();
                cur_node->children[i] = child_node;
            }
            cur_node = cur_node->children[i];
        }
        cur_node->isword = true;
    }
    
    bool search_sol(string word, TrieNode* cur_node) {
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                for(auto child : cur_node->children){
                    if(search_sol(word.substr(i+1), child.second)){
                        return true;
                    }
                }
                return false;
            }else{
                if(cur_node->children.find(word[i]) == cur_node->children.end()){
                    return false;
                }
                cur_node = cur_node->children[word[i]];
            }
        }
        // cout << word << endl;
        return cur_node->isword;
    }

    bool search(string word) {
        return search_sol(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */