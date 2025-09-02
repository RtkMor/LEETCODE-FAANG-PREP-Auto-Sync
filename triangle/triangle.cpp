class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, vector<int> dp){
        if(i==triangle.size()-1) return dp[i] = triangle[i][j];

        if(dp[i]) return dp[i];

        return dp[i] = triangle[i][j] + min(solve(triangle, i+1, j, dp), solve(triangle, i+1, j+1, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> curr(m, 0);
        vector<int> prev(m, 0);
        for(int j=0 ; j<m ; j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=0 ; j<triangle[i].size() ; j++){
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
            prev = curr;
        }

        return prev[0];
    }
};