class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int sum = 0;
        int ans = n+1;
        while((ptr1<n && ptr2<n) || sum>=target){
            if(sum<target){
                sum += nums[ptr2];
                ptr2++;
            }
            else{
                ans = min(ans, ptr2-ptr1);
                sum -= nums[ptr1];
                ptr1++;
            }

            if(ans == 1) return ans;
        }

        if(ans==n+1) return 0;
        return ans;
    }
};