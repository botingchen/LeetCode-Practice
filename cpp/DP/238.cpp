class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_prod(n);
        vector<int> right_prod(n);
        vector<int> ans;
        left_prod[0] = 1;
        for(int i=0; i<n-1; i++) left_prod[i+1] = left_prod[i] * nums[i];
        right_prod[n-1] = 1;
        for(int i=n-1; i>0; i--) right_prod[i-1] = right_prod[i] * nums[i];
        for(int i=0; i<n; i++) ans.push_back(left_prod[i] * right_prod[i]);
        return ans;
    }
};

//Folow Up, Space Complexity O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=0; i<n-1; i++) ans[i+1] = ans[i] * nums[i];
        int right = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};