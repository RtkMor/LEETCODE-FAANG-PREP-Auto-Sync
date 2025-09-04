class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        unordered_map<int,int> mp;
        while(ptr2<n){
            if(ptr2-ptr1<k){
                sum += nums[ptr2];
                mp[nums[ptr2]]++;
                while(mp[nums[ptr2]]>1){
                    sum -= nums[ptr1];
                    mp[nums[ptr1]]--;   
                    ptr1++;
                }
                ptr2++;
            }
            else {
                sum -= nums[ptr1];
                mp[nums[ptr1]]--;
                ptr1++;
            }
            if(ptr2-ptr1 == k){
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};