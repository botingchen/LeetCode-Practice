//update left when prices[left] is bigger than prices[right]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right < prices.size()){
            int profit = prices[right] - prices[left];
            if(prices[right] < prices[left]){
                left = right;
            }
            else{
                ans = max(ans, profit);
            }
            right++;
        }
        return ans;
    }
};