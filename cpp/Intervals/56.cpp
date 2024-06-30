class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int i = 0;
        int j = i;
        sort(intervals.begin(), intervals.end());
        
        while(i < intervals.size()){
            j = i;
            i++;
            while(i < intervals.size() && !(intervals[i][0] > intervals[j][1] || intervals[i][1] < intervals[j][0])){
                intervals[j] = {min(intervals[j][0], intervals[i][0]), max(intervals[j][1], intervals[i][1])};
                i++;
            }
            ans.push_back(intervals[j]);
        }
        return ans;
    }
};