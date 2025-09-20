#include <iostream>
#include <vector>
using namespace std;

bool isBipartite(int node, vector<int>& color, const vector<vector<int>>& adj) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            color[neighbor] = 1 - color[node];
            if (!isBipartite(neighbor, color, adj))
                return false;
        } else if (color[neighbor] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize Adjacency and Visited vectors
    vector<vector<int>> adj(n);
    vector<int> color(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check bipartite
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!isBipartite(i, color, adj)) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    // Print one partition
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            cout << i << " ";
    cout << "\n";

    return 0;
}


/* 
Input -> 
n (number of nodes)
m (number of edges)
u1 v1
u2 v2
... so on (defining edges btw u and v)
*/
