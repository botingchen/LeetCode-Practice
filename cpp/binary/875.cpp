//do binary search from 1 to the maximum in the given vector
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left<right){
            int mid = left + (right-left)/2;
            int total = 0;
            for(auto i : piles){
                // total += ceil((double)i/mid); //slower!!!
                total += (i-1)/mid + 1;          //faster!!!
            }
            if(total > h) left = mid+1;
            else right = mid;
        }
        return left;
    }
};