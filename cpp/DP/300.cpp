class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        if(nums.size() == 1) return 1;
        for(int i = 0; i < nums.size(); i++){
            if(dp.empty() || dp[dp.size() - 1] < nums[i]) dp.push_back(nums[i]);
            else{
                for(int j = 0; j < dp.size(); j++){     // Find first element that >= nums[i] and replace it with nums[i]
                    if(dp[j] >= nums[i]){       
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return dp.size();
    }
};