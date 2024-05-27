class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size()-1];
        while(left < right){
            int mid = (left + right) / 2;
            int count = 0;
            for(auto i : nums){
                if(i >= mid) count++;
            }
            if(mid == count) return count;
            else{
                if(count > mid) left = mid + 1;
                else right = mid;
            }
        }
        int count = 0;
        for(auto i : nums){
            if(i >= (right+left)/2) count++;
        }
        if((right+left)/2 == count) return count;
        return -1;
    }
};