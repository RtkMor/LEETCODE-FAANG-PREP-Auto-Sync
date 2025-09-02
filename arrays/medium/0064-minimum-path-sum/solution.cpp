class Solution {
public:
    // int solve(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp){
    //     if(i==n-1 && j==m-1){
    //         return grid[i][j];
    //     }

    //     if(dp[i][j]) return dp[i][j];

    //     int down = INT_MAX;
    //     int right = INT_MAX;

    //     if(i<n-1){
    //         down = grid[i][j] + solve(grid, i+1, j, n, m, dp);
    //     }
    //     if(j<m-1){
    //         right = grid[i][j] + solve(grid, i, j+1, n, m, dp);
    //     }

    //     return dp[i][j] = min(down, right);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));

        // Base case: bottom-right cell
        dp[n-1][m-1] = grid[n-1][m-1];
        
        // Fill last row (only right moves possible)
        for (int j = m - 2; j >= 0; j--) {
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }
        // Fill last column (only down moves possible)
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=m-2 ; j>=0 ; j--){
                dp[i][j] = min(grid[i][j] + dp[i+1][j], grid[i][j] + dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};