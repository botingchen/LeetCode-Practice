class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 0;
        int r = 0;
        int count = 0;
        while(r < nums.size() - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, nums[i] + i);
            }
            l = r+1;
            r = farthest;
            count++;
        }
        return count;
    }
};