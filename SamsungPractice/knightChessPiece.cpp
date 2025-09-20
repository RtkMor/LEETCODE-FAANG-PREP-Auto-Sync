#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findMinimumMoves(){
    int n;
    cin >> n;
    
    int s1, s2, d1, d2;
    cin >> s1 >> s2 >> d1 >> d2;
    
    if (s1 == d1 && s2 == d2) {
        cout << 0 << endl;
        return;
    }
    
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    
    q.push({s1, s2});
    vis[s1][s2] = 1;
    
    int level = 0;
    
    vector<int> movesX = {2, -2, 2, -2, 1, 1, -1, -1};
    vector<int> movesY = {1, 1, -1, -1, 2, -2, 2, -2};
    
    while (!q.empty()) {
        level++;
        int levelSize = q.size();
        
        for (int l = 0; l < levelSize; l++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                int newX = x + movesX[i];
                int newY = y + movesY[i];
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]) {
                    if (newX == d1 && newY == d2) {
                        cout << level << endl;
                        return;
                    }
                    
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    
    cout << "-1" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for(int i=0 ; i<t ; i++){
        findMinimumMoves();
    }
    return 0;
}
