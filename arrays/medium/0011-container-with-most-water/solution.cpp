class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0;
        int ptr2 = height.size()-1;

        int maxLeft = height[ptr1];
        int maxRight = height[ptr2];

        int ans = 0;

        while(ptr1<ptr2){
            int left = height[ptr1];
            int right = height[ptr2];

            maxLeft = max(maxLeft, left);
            maxRight = max(maxRight, right);

            if(maxLeft<=maxRight){
                ans = max(ans, maxLeft*(ptr2-ptr1));
                ptr1++;
            }
            else{
                ans = max(ans, maxRight*(ptr2-ptr1));
                ptr2--;
            }
        }

        return ans;
    }
};