class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int low=0 ; low<n ; low++){
            if(low!=0 && nums[low]==nums[low-1]) continue;
            bool flag1 = false;
            for(int mid1=low+1 ; mid1<n ; mid1++){
                if(flag1){
                    if(nums[mid1]==nums[mid1-1]){
                        continue;
                    }
                    flag1 = false;
                }
                int mid2 = mid1+1;
                int high = n-1;
                bool flag2 = false;
                while(mid2<high){
                    long long sum = (long long)nums[low] + nums[mid1] + nums[mid2] + nums[high];
                    if(flag2){
                        if(nums[mid2]==nums[mid2-1]){
                            mid2++;
                            continue;
                        }
                        flag2 = false;
                    }
                    if(sum==target){
                        ans.push_back({nums[low], nums[mid1], nums[mid2], nums[high]});
                        flag1 = true;
                        flag2 = true;
                        mid2++;
                        high--;
                    }
                    else if(sum<target){
                        mid2++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};