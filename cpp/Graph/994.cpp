class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& myq){
        int count = 0;
        while(!myq.empty()){
            int n = myq.size();
            while(n--){
                auto [i, j] = myq.front();
                myq.pop();
                if(grid[i][j] == 0 || grid[i][j] == -1) continue;
                grid[i][j] = -1;
                if(i + 1 < grid.size() && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    myq.push({i + 1, j});
                }
                if(i - 1 >= 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    myq.push({i - 1, j});
                }
                if(j + 1 < grid[0].size() && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    myq.push({i, j + 1});
                }
                if(j - 1 >= 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    myq.push({i, j - 1});
                }              
            }
            if(myq.size() > 0) count++;
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> myq;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    myq.push({i, j});
                }
            }
        }
        res = bfs(grid, myq);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};