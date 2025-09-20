#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// Using a type alias for a pair to represent a location Point
using Point = pair<int, int>;

// Helper function to calculate Manhattan distance
int calculateDist(Point p1, Point p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// Recursive DFS to find the minimum path by exploring all permutations
void findMinPath(int curr_node_idx, int visited_count, int current_dist,
                 int n, vector<bool>& visited, const vector<Point>& locations, int& min_dist) {
    
    // Base Case: If all N customers have been visited
    if (visited_count == n) {
        // Calculate the final distance from the last customer to home and update the minimum
        int final_dist = current_dist + calculateDist(locations[curr_node_idx], locations[n + 1]);
        min_dist = min(min_dist, final_dist);
        return;
    }

    // Recursive Step: Explore all unvisited customers
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int dist_to_next = calculateDist(locations[curr_node_idx], locations[i]);
            findMinPath(i, visited_count + 1, current_dist + dist_to_next,
                        n, visited, locations, min_dist);
            // Backtrack to explore other paths
            visited[i] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    // Locations vector: 0=Office, 1 to n=Customers, n+1=Home
    vector<Point> locations(n + 2);
    vector<bool> visited(n + 2, false);
    int min_dist = INT_MAX;

    // Input order: Office, Home, then N customers
    cin >> locations[0].first >> locations[0].second;       // Office
    cin >> locations[n + 1].first >> locations[n + 1].second; // Home
    for (int i = 1; i <= n; i++) {
        cin >> locations[i].first >> locations[i].second;     // Customers
    }

    // Start DFS from the office (index 0)
    findMinPath(0, 0, 0, n, visited, locations, min_dist);

    cout << min_dist << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
