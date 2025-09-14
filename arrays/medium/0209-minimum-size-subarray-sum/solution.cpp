class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0;

        int currSum = 0;
        int ans = INT_MAX;

        for(int i=0 ; i<n ; i++){
            currSum += nums[i];
            while(currSum >= target){
                ans = min(ans, i-ptr1+1);
                currSum -= nums[ptr1];
                ptr1++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};