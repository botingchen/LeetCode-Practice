class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[i] + nums[j] > 0){
                    break;
                }
                while(nums[j] + nums[k] < 0 && j<k) j++;
                if(nums[j]+nums[k] < 0-nums[i]) j++;
                else if(nums[j]+nums[k] > 0-nums[i]) k--;
                else{
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(j<k && nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    else if(sum < 0) j++;
                    else if(sum > 0) k--;
                }

            }
        }
        return ans;
    }
};