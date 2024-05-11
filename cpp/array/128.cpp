class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }        
        int ans = 0;
        int y = 0;
        for(auto num : set){
            if(!set.contains(num-1)){
                y = num + 1;
                while(set.contains(y)){
                    cout<<y;
                    y++;
                }
                ans = max(ans, y-num);
            }
        }
        return ans;
    }
};