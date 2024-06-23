//Priority Queue
class Solution {
public:
    struct freq_order {
        bool operator()(const pair<int, int> l, const pair<int, int> r){
            if(l.second == r.second){
                return l.first > r.first;
            }
            return l.second > r.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap; //first=num, second=freq
        vector<int> ans;
        for(auto i : nums){
            mymap[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, freq_order> MinHeap;
        for(auto&[key, val] : mymap){
            MinHeap.push({key, val});
            if(MinHeap.size() > k){
                MinHeap.pop();
            }
        }
        while(!MinHeap.empty()){
            ans.push_back(MinHeap.top().first);
            MinHeap.pop();
        }
        return ans;
    }
};

//Bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        vector<int> ans;
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        for (auto p : counter) {
            buckets[p.second].push_back(p.first);
        }
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            if (!buckets[i].empty()) {
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return ans;
    }
};