class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || i == 1) dp[i] = nums[i];
            else if(i == 2) dp[i] = dp[0] + nums[i];
            else dp[i] = (max(dp[i-2], dp[i-3]) + nums[i]);
        }
        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};