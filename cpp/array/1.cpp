class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp; // first int = value, second value = index
        mp[nums[0]] = 0;
        for(int i=1;i<nums.size();i++){
            if(mp.count(target-nums[i])){
                return {mp[target-nums[i]],i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};
