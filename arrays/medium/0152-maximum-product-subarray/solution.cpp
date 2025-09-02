class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prod1 = 1;
        int prod2 = 1;
        for(int i=0 ; i<n ; i++){
            prod1 *= nums[i];
            prod2 *= nums[n-1-i];
            ans = max(ans, max(prod1, prod2));
            if(prod1==0) prod1 = 1;
            if(prod2==0) prod2 = 1;
        }
        return ans;
    }
};