class Solution {
public:
    priority_queue<int, vector<int>> mypq;
    int lastStoneWeight(vector<int>& stones) {
        for(int i = 0;i < stones.size(); i++){
            mypq.push(stones[i]);
        }
        while(mypq.size() >= 2){
            int st1 = mypq.top();
            mypq.pop();
            int st2 = mypq.top();
            mypq.pop();
            if(st1 > st2) mypq.push(st1 - st2);
        }
        if(mypq.size()) return mypq.top();
        return 0;
    }
};