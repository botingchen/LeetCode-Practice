class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tmp = {0,0,0};
        int j = 0;
        while(j < triplets.size() && triplets[j] != target){
            if(triplets[j][0] <= target[0] && triplets[j][1] <= target[1] && triplets[j][2] <= target[2]){
                triplets[j][0] = max(triplets[j][0], tmp[0]);
                triplets[j][1] = max(triplets[j][1], tmp[1]);
                triplets[j][2] = max(triplets[j][2], tmp[2]);
                tmp = triplets[j];
            }
            j++;
        }
        if(j >= triplets.size()){
            if(tmp != target) return false;            
        }
        return true;
    }
};