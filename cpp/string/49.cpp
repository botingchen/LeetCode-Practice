class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>record;
        for(auto tmp : strs){
            string word = tmp;
            sort(word.begin(), word.end());
            record[word].push_back(tmp);
        }
        vector<vector<string>> ans;
        for(auto tmp : record){
            ans.push_back(tmp.second);
        }
        return ans;
    }
};