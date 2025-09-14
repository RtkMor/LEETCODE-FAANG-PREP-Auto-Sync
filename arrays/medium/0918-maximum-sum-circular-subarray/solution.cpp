class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int totalSum = 0, currSum1 = 0, currSum2 = 0;

        for(int i=0 ; i<n ; i++){
            totalSum += nums[i];
            currSum1 += nums[i];
            currSum2 += nums[i];

            maxi = max(maxi, currSum1);
            mini = min(mini, currSum2);
            
            if(currSum1<0) currSum1 = 0;
            if(currSum2>0) currSum2 = 0;
        }

        if(totalSum == mini) return maxi;
        return max(maxi,totalSum - mini);
    }
};