class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step_cnt = nums[0];
        int i = 1;
        if(nums.size() == 1) return true;
        while(step_cnt > 0){
            step_cnt--;
            if(i == nums.size() - 1) return true;
            if(step_cnt < nums[i]) step_cnt = nums[i];
            i++;
        }
        return false;
        
    }
};