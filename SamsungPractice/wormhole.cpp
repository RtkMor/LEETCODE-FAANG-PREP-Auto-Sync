#include <bits/stdc++.h>

using namespace std;

using Point = pair<int,int>; // {x, y}
using State = pair<int,int>; // {distance, node_ind}

int calculateDist(Point p1, Point p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solve(){
    int n;
    cin >> n;
    
    int num_nodes = 2*n + 2;
    vector<Point> locations(num_nodes);
    vector<vector<int>> wormholes(n);
    
    // Take source and destination inputs
    cin >> locations[0].first >> locations[0].second;
    cin >> locations[num_nodes-1].first >> locations[num_nodes-1].second;
    
    for(int i=0 ; i<n ; i++){
        int ind1 = 2*i + 1;
        int ind2 = 2*i + 2;
        int cost;
        
        cin >> locations[ind1].first >> locations[ind1].second >> locations[ind2].first >> locations[ind2].second >> cost;
        wormholes[i] = {ind1, ind2, cost};
    }
    
    vector<int> dist(num_nodes, INT_MAX);
    
    priority_queue<State, vector<State>, greater<State>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        int d = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        
        if(d>dist[currNode]) continue;
        
        // We can travel to any other node
        for(int neighbour=0 ; neighbour<num_nodes ; neighbour++){
            if(neighbour==currNode) continue;
            // Calculate Travel Cost (Manhattan Distance)
            int travelCost = calculateDist(locations[currNode], locations[neighbour]);
            // Check if the wormhole provide shortcut
            for (const auto& w : wormholes) {
                if ((w[0] == currNode && w[1] == neighbour) || (w[0] == neighbour && w[1] == currNode)) {
                    travelCost = min(travelCost, w[2]);
                }
            }
            // If we found a shorter path to neighbour through currNode, update it
            if(dist[currNode] != INT_MAX && dist[currNode]+travelCost < dist[neighbour]){
                dist[neighbour] = dist[currNode]+travelCost;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    
    cout << dist[num_nodes-1] << endl;
    
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
