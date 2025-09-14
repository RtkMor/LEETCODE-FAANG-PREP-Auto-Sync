class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = nums.size()-1;

        for(int i=0 ; i<=ptr2 ; i++){
            int num = nums[i];

            if(num==0){
                swap(nums[i], nums[ptr1]);
                ptr1++;
            }
            else if(num==2){
                swap(nums[i], nums[ptr2]);
                ptr2--;
                i--;
            }
        }

        return;
    }
};