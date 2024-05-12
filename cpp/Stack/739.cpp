class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> mystack;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!mystack.empty() && temperatures[mystack.top()] < temperatures[i]){
                ans[mystack.top()] = i - mystack.top();
                mystack.pop();
            }
            mystack.push(i);
        }
        return ans;
    }
};