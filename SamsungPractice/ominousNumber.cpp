#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to check if a single number is "valid"
bool isValid(long long num, int k, const vector<bool>& is_forbidden) {
    int forbidden_count = 0;
    string s = to_string(num);

    // Count the total number of forbidden digits in the number
    for (char c : s) {
        if (is_forbidden[c - '0']) {
            forbidden_count++;
        }
    }

    // A number is valid if the count of forbidden digits is less than k
    return forbidden_count < k;
}

void solve() {
    // Range -> a to b
    long long a, b;
    // Forbidden count should not be more than or equal to k
    // n -> count of forbidden digits
    int k, n;
    cin >> a >> b >> k;
    cin >> n;

    // Use a boolean vector for O(1) lookup of forbidden digits
    vector<bool> is_forbidden(10, false);
    for (int i = 0; i < n; i++) {
        int forbidden_digit;
        cin >> forbidden_digit;
        is_forbidden[forbidden_digit] = true;
    }

    int valid_count = 0;
    // Iterate through every number in the range [a, b]
    for (long long i = a; i <= b; i++) {
        // If the number meets the criteria, increment the count
        if (isValid(i, k, is_forbidden)) {
            valid_count++;
        }
    }

    cout << valid_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Assuming a single test case based on the problem description
    solve();

    return 0;
}
