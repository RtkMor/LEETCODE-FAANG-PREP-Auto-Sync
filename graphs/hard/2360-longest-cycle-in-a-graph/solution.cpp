class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& currVis, vector<int>& path, int& maxCycle) {
        vis[node] = 1;
        currVis[node] = 1;
        path.push_back(node);

        int next = edges[node];
        if (next != -1) {
            if (!vis[next]) {
                dfs(next, edges, vis, currVis, path, maxCycle);
            } else if (currVis[next]) {
                // Cycle detected, compute cycle length
                auto it = find(path.begin(), path.end(), next);
                int cycleLength = path.end() - it;
                maxCycle = max(maxCycle, cycleLength);
            }
        }

        path.pop_back();
        currVis[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> currVis(n, 0);
        int maxCycle = -1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> path;
                dfs(i, edges, vis, currVis, path, maxCycle);
            }
        }

        return maxCycle;
    }
};