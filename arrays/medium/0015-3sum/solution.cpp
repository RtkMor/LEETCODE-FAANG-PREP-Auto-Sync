class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int low=0 ; low<n ; low++){
            if(low>0 && nums[low]==nums[low-1]) continue;
            int mid = low+1;
            int high = n-1;
            bool flag = false;
            while(mid<high){
                if(flag){
                    if(nums[mid]==nums[mid-1]){
                        mid++;
                        continue;
                    }
                    flag = false;
                }
                int sum = nums[low] + nums[mid] + nums[high];
                if(sum==0){
                    ans.push_back({nums[low], nums[mid], nums[high]});
                    mid++;
                    high--;
                    flag = true;
                }
                else if(sum<0){
                    mid++;
                }
                else{
                    high--;
                }
            }
        }

        return ans;
    }
};