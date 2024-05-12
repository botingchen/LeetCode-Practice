class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int w = right - left;
            int h = min(height[left], height[right]);
            ans = max(ans, w * h);
            if(height[left] < height[right]) left++;    //move the lower one
            else right--;
        }
        return ans;
    }
};