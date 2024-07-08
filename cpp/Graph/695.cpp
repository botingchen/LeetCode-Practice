class Solution {
public:
    vector<vector<bool>> visited;
    void dfs(vector<vector<int>>& grid, int i, int j, int& area){
        if(visited[i][j]) return;
        if(grid[i][j] == 1){
            visited[i][j] = true;
            area++;
        }
        if(i + 1 < grid.size() && grid[i + 1][j] == 1) dfs(grid, i + 1, j, area);
        if(i - 1 >= 0 && grid[i - 1][j] == 1) dfs(grid, i - 1, j, area);
        if(j + 1 < grid[0].size() && grid[i][j + 1] == 1) dfs(grid, i, j + 1, area);
        if(j - 1 >= 0 && grid[i][j - 1] == 1) dfs(grid, i, j - 1, area);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int answer = 0;
        int height = grid.size();
        int width = grid[0].size();
        visited = vector<vector<bool>>(height, vector<bool>(width, false));
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int tmp = area;
                    dfs(grid, i ,j, area);
                    answer = max(answer, area - tmp);
                }
            }
        }
        return answer;
    }
};