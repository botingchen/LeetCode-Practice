class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        mymap[0] = 1;
        int total = 0;
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            int remainder = total % k;
            while(remainder < 0){
                remainder += k;
            }
            if(mymap.find(remainder) != mymap.end()){
                answer+=mymap[remainder];
                mymap[remainder]++;
            }
            else{
                mymap[remainder] = 1;
            }
        }
        return answer;
    }
};