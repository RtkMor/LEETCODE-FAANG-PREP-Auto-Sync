#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &currVis, vector<int> &path, vector<int> &cycle){
    vis[node] = 1;
    currVis[node] = 1;
    path.push_back(node);
    for (int neighbour : adj[node]) {
        if (!vis[neighbour] && dfs(neighbour, adj, vis, currVis, path, cycle))
            return true;
        else if (currVis[neighbour]){
            auto it = find(path.begin(), path.end(), neighbour);
            cycle.assign(it, path.end());
            cycle.push_back(neighbour);
            return true;
        }
    }
    path.pop_back();
    currVis[node] = 0;
    return false;
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);
    vector<int> currVis(n,0);
    vector<int> path;
    vector<int> cycle;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int u;
            cin >> u;
            if(u==1){
                adj[i].push_back(j);
            }
        }
    }
    
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, currVis, path, cycle)){
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
