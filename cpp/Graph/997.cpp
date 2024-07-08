class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mymap;
        if(n == 1 && trust.size() == 0) return n;
        int ppl = 0;
        for(int i = 0; i < trust.size(); i++){
            if(mymap.find(trust[i][0]) == mymap.end()){
                mymap[trust[i][0]] = -1;
                ppl++;
            }
            if(mymap.find(trust[i][1]) == mymap.end()){
                mymap[trust[i][1]] = 0;
                ppl++;
            }
            mymap[trust[i][0]] = -1;

            if(mymap[trust[i][1]] == -1) continue;
            mymap[trust[i][1]]++;                
        }
        int count  = 0;
        int ans = 0;
        for(auto i:mymap){
            if(i.second == ppl - 1){
                count++;
                ans = i.first;
            }
        }
        if(count != 1) return -1;
        return ans;
    }
};