class Solution {
public:

    vector<int> dir = {1,-1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int ans = 0;
        int count = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1) count++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }

        while(count>0 && !q.empty()){
            ans++;
            int size = q.size();
            while(size){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0 ; j<4 ; j++){
                    int newR = r + dir[j];
                    int newC = c + dir[3-j];
                    if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1){
                        q.push({newR, newC});
                        grid[newR][newC] = 2;
                        count--;
                    }
                }
                size--;
            }
        }

        if(count>0) return -1;
        return ans;
    }
};