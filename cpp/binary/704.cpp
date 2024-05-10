class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0 || (nums.size() == 1 && nums[0]!= target)){
            return -1;
        }
        int idx = 0;
        int left = 0;
        int right = nums.size()-1;
        while(right>left){
            idx = right - left / 2;
            if(nums[idx] == target){
                return idx;
            }
            if(nums[idx] < target){
                left = idx + 1;
            }else if(nums[idx] > target){
                right = idx -1;
            }
        }
        if(nums[right] == target) return right;
        return -1;
    }
};