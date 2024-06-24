class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                if(isFlipped[i - k] == 1){
                    flipped = flipped == 1? 0:1;    // exceed range k, erase the effect of flipped
                }
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                if(flipped == 0) flipped++;
                else flipped--;
                res++;
            }
        }

        return res;
    }
};