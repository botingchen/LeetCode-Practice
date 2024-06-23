class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mypq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(int i = 0; i<nums.size(); i++){
            mypq.push(nums[i]);
            if(mypq.size() > k) mypq.pop();
        }
    }
    
    int add(int val) {
        mypq.push(val);
        if(mypq.size() > k1) mypq.pop();
        return mypq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */