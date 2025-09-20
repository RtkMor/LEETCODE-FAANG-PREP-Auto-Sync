#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int> &stalls, int dist, int cows) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            cowsPlaced++;
            lastPos = stalls[i];
        }
    }
    return cowsPlaced >= cows;
}

int aggressiveCows(vector<int> &stalls, int c) {
    sort(stalls.begin(), stalls.end());
    
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, mid, c)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> stalls(n);
    for(int i=0 ; i<n ; i++){
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());

    int ans = aggressiveCows(stalls, c);
    cout << "The largest minimum distance is: " << ans << endl;
    
    return 0;
}
