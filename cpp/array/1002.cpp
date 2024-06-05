class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<string, int> map;
        vector<string> ans;
        string base = words[0];
        for(auto i : base){
            int count = 0;
            string tmp(1, i);
            for(int j = 1; j < words.size(); j++){
                auto it = words[j].find(tmp);
                if( it != std::string::npos){
                    words[j].erase(words[j].begin() + it);
                    count++;
                }
            }
            if(count == words.size() - 1) ans.push_back(tmp);
        }
        return ans;
    }
};