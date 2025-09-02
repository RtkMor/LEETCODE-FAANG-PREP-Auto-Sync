class Solution {
public:

    int solve(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int a = solve(matrix, i, j-1, dp);
        int b = solve(matrix, i-1, j, dp);
        int c = solve(matrix, i-1, j-1, dp);

        if(matrix[i][j]=='1'){
            return dp[i][j] = 1 + min({a,b,c});
        }
        return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxSide = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                maxSide = max(maxSide, solve(matrix, i, j, dp));
            }
        };

        return maxSide * maxSide;
    }
};