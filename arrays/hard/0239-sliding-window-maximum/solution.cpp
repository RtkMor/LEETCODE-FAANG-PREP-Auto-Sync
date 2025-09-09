class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector <int> ans;
        deque<int> dq;

        for(int i=0 ; i<n ; i++){

            int num = nums[i];
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<=num){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};