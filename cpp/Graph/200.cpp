class Solution {
public:
    int count;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(visited[i][j]) return;
        if(grid[i][j] == '1') visited[i][j] = true;
        if(i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, visited, i+1, j);
        if(i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, visited, i-1, j);
        if(j + 1 < grid[0].size() && grid[i][j+1] == '1') dfs(grid, visited, i, j+1);
        if(j - 1 >= 0 && grid[i][j-1] == '1') dfs(grid, visited, i, j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size());
        count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                visited[i].push_back(false);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};