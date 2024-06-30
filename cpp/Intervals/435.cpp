class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int j = 0;
        int count = 0;
        while(i < intervals.size()){
            if(intervals[i][0] >= intervals[j][1]){
                j = i;
            }
            else if(intervals[j][1] <= intervals[i][1]){
                count++;
            }
            else if(intervals[j][1] > intervals[i][1]){
                count++;
                j = i;
            }
            i++;
        }
        return count;
    }
};