#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using Point = pair<int, int>;

// Helper function to determine orientation using cross-product.
// > 0 for counter-clockwise turn
// < 0 for clockwise turn
//   0 for collinear points
long long cross_product(Point a, Point b, Point c) {
    long long x1 = (long long)b.first - a.first;
    long long y1 = (long long)b.second - a.second;
    long long x2 = (long long)c.first - b.first;
    long long y2 = (long long)c.second - b.second;
    return x1 * y2 - x2 * y1;
}

// Main logic function to find and print the convex hull
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "-1";
        return;
    }

    // Sort points lexicographically (by x, then by y)
    sort(points.begin(), points.end());

    vector<Point> lower_hull;
    vector<Point> upper_hull;
    for (const auto& p : points) {
        while (lower_hull.size() >= 2 && cross_product(lower_hull[lower_hull.size() - 2], lower_hull.back(), p) <= 0) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(p);
    }

    
    for (int i = n - 1; i >= 0; i--) {
        const auto& p = points[i];
        while (upper_hull.size() >= 2 && cross_product(upper_hull[upper_hull.size() - 2], upper_hull.back(), p) <= 0) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(p);
    }

    // Combine the lower and upper hulls
    vector<Point> hull = lower_hull;
    for (size_t i = 1; i < upper_hull.size() - 1; i++) {
        hull.push_back(upper_hull[i]);
    }

    // A final check for degenerate cases (e.g., all points are collinear)
    if (hull.size() < 3) {
        cout << "-1";
        return;
    }

    for (size_t i = 0; i < hull.size(); i++) {
        cout << hull[i].first << " " << hull[i].second;
        if (i != hull.size() - 1) {
            cout << ", ";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        convexHull(points);
        cout << "\n";
    }

    return 0;
}
