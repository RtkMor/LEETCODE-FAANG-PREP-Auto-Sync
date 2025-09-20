#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, vector<int>&nums, vector<vector<int>> &dp){
    if(i>j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int maxi = 0;
    for(int k=i ; k<=j ; k++){
        int score = nums[i-1] * nums[k] * nums[j+1];
        int remainingScore = solve(k+1, j, nums, dp) + solve(i, k-1, nums, dp);
        maxi = max(maxi, score+remainingScore);
    }
    
    return dp[i][j] = maxi;
}

int burstBalloon(vector<int> &nums, int n){
    vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return solve(1, n, nums, dp);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums;
    int i;
    
    while(cin >> i){
        nums.push_back(i);
    }
    
    int ans = burstBalloon(nums, n);
    cout << ans << endl;
    return 0;
}
