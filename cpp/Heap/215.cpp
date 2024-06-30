//Priority Queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mypq;
        for(int i = 0; i < nums.size(); i++){
            if(mypq.size() >= k && mypq.top() < nums[i]){
                mypq.pop();
                mypq.push(nums[i]);
            }
            else if(mypq.size() < k) mypq.push(nums[i]);
        }
        return mypq.top();
        
    }
};