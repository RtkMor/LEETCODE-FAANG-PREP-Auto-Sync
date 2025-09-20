#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int parent, vector<int> &path, vector<int> &cycle){
    vis[node] = 1;
    path.push_back(node);
    for(int neighbour: adj[node]){
        if(!vis[neighbour]){
            if(dfs(neighbour, adj, vis, node, path, cycle)){
                return true;
            }
        } else {
            if(neighbour != parent){
                auto it = find(path.begin(), path.end(), neighbour);
                cycle.assign(it, path.end());
                cycle.push_back(neighbour);
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);
    vector<int> path, cycle;
    int parent = -1;
    
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, parent, path, cycle)){
                cout << "Cycle Found" << endl;
                for(auto val:cycle){
                    cout << val << " ";
                }
                return 0;
            }
        }
    }
    
    cout << "Cycle Did Not Found" << endl;
    
    return 0;
}
