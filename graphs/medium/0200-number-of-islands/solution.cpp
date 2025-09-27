class Solution {
public:
    
    vector<int> vertical = {0,0,1,-1};
    vector<int> horizontal = {1,-1,0,0};

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j] = 1;
                    ans++;
                }
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int k=0 ; k<4 ; k++){
                        int newRow = row + vertical[k];
                        int newCol = col + horizontal[k];
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                            q.push({newRow, newCol});
                            vis[newRow][newCol] = 1;
                        }
                    }
                }
            }
        }

        return ans;
    }
};