class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int dp2[n];
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        for(int i = 0; i < n; i++){
            if(i == 0 || i == 1) dp[i] = nums[i];
            else if(i == 2) dp[i] = dp[0] + nums[i];
            else if(i == n - 1) dp[i] = max(dp[i-1], dp[i-2]);
            else dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 || i == n -2) dp2[i] = nums[i];
            else if(i == n -3) dp2[i] = dp2[n-1] + nums[i];
            else if(i == 0) dp2[i] = max(dp2[i + 1], dp2[i + 2]);
            else dp2[i] = max(dp2[i + 2], dp2[i + 3]) + nums[i];
        }
        return max(dp2[0], dp[n - 1]);
    }
};