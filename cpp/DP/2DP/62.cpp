// Combinatorics solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};

// DP solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - 1];
            }
        }
        return dp[(m-1) % 2][n-1];
    }
};