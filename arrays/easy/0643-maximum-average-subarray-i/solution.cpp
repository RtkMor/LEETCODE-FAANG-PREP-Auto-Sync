class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double windowSum = 0;
        for(int i=0 ; i<k ; i++){
            windowSum += nums[i];
        }

        double ans = windowSum/k;

        for(int i=k ; i<n ; i++){
            windowSum += nums[i];
            windowSum -= nums[i-k];
            ans = max(ans, windowSum/k);
        }

        return ans;
    }
};