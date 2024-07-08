class Solution {
public:
    int width;
    int height;
    vector<vector<bool>> atlantic;
    vector<vector<bool>> pacific;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& map, vector<vector<bool>>& cur_vec, int i, int j){
        if(cur_vec[i][j]) return;
        cur_vec[i][j] = true;
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
        if(i + 1 < height && map[i + 1][j] >= map[i][j]) dfs(map, cur_vec, i + 1, j);
        if(i - 1 >= 0 && map[i - 1][j] >= map[i][j]) dfs(map, cur_vec, i - 1, j);
        if(j + 1 < width && map[i][j + 1] >= map[i][j]) dfs(map, cur_vec, i, j + 1);
        if(j - 1 >= 0 && map[i][j - 1] >= map[i][j]) dfs(map, cur_vec, i, j - 1);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0) return ans;
        height = heights.size();
        width = heights[0].size();
        atlantic = pacific = vector<vector<bool> >(height, vector<bool>(width, false));

        for(int i = 0; i < height; i++){
            dfs(heights, atlantic, i, 0);
            dfs(heights, pacific, i, width- 1);
        }
        for(int i = 0; i < width; i++){
            dfs(heights, atlantic, 0, i);
            dfs(heights, pacific, height - 1, i);
        }
        return ans;
    }
};