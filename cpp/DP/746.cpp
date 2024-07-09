class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        else if(cost.size() == 2) return min(cost[0], cost[1]);
        int myarr[cost.size()];
        myarr[0] = cost[0];
        myarr[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            myarr[i] = min(myarr[i - 2], myarr[i - 1]) + cost[i];
        }
        return min(myarr[cost.size() - 1], myarr[cost.size() - 2]);
    }
};