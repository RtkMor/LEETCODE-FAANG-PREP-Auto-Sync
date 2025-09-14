class Solution {
public:
    int trap(vector<int>& height) {
        
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        int ans = 0;

        int maxLeft = height[ptr1];
        int maxRight = height[ptr2];

        while(ptr1<ptr2){
            int left = height[ptr1];
            int right = height[ptr2];

            maxLeft = max(maxLeft, left);
            maxRight = max(maxRight, right);

            if(maxLeft<=maxRight){
                ans += maxLeft - left;
                ptr1++;
            }
            else{
                ans += maxRight - right;
                ptr2--;
            }
        }

        return ans;
    }
};