class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        int total = 0;
        mymap[0] = -1;
        for(int i = 0; i< nums.size(); i++){
            total += nums[i];
            int remainder = 0;
            if(k==0) remainder = total;
            else remainder = total % k;
            cout << remainder << endl;
            if(mymap.find(remainder) != mymap.end()){
                if(i - mymap[remainder] > 1) return true;
            }
            else{
                mymap[remainder] = i;
            }
        }
        return false;
    }
};