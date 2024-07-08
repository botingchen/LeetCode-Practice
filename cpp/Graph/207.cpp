//use bfs and count down
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pre_num(numCourses, 0);
        vector<int> adj_course[numCourses];
        vector<int> ans;
        queue<int> myq;

        for(auto i: prerequisites){
            adj_course[i[0]].push_back(i[1]);
            pre_num[i[1]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(pre_num[i] == 0) myq.push(i);
        }
        while(!myq.empty()){
            int cur_course = myq.front();
            ans.push_back(cur_course);
            myq.pop();

            for(auto i : adj_course[cur_course]){
                pre_num[i]--;
                if(pre_num[i] == 0) myq.push(i);
            }
        }
        return ans.size() == numCourses;
    }
};

//DFS + cyclic detector solution
class Solution {
public:
    bool dfs(int coursenum, unordered_map<int, vector<int>>& premap, set<int>& visited){
        if(visited.count(coursenum) != 0) return false;
        if(premap[coursenum].size() == 0) return true;
        visited.insert(coursenum);
        for(int i : premap[coursenum]){
            if(!dfs(i, premap, visited)) return false;
        }
        visited.erase(coursenum);
        premap[coursenum].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> premap;
        set<int> visited;
        vector<int> v;
        for(int i = 0; i < prerequisites.size(); i++){
            if(premap.find(prerequisites[i][0]) == premap.end()){
                premap[prerequisites[i][0]] = v;
            }
            premap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, premap, visited)) return false;
        }
        return true;        
    }
};