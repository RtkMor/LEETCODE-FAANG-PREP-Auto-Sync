class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size()-1;
        while(ptr1<ptr2){
            int sum = numbers[ptr1] + numbers[ptr2];
            if(sum==target){
                return {ptr1+1, ptr2+1};
            }
            else if(sum<target){
                ptr1++;
            }
            else{
                ptr2--;
            }
        }
        return {-1, -1};
    }
};