class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int j = 1;
        int k = nums.size() - 1;
        int cur = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++){
            j = i + 1;
            k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(cur - target)){
                    cur = sum;
                }
                if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return cur;

    }
};