class Solution {
public:
    int find(vector<int> sub, int target){
        int low = 0;
        int high = sub.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target==sub[mid]){
                return mid;
            }
            else if(target>sub[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        for(int i=0 ; i<n ; i++){
            int s = sub.size();
            int target = nums[i];
            if(s==0 || target>sub[s-1]){
                sub.push_back(target);
            }
            else{
                int ind = find(sub, target);
                sub[ind] = target;
            }
        }
        return sub.size();
    }
};