class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int>m1,m2;
        for(int i=0 ; i<k ; i++)
            m1.insert(nums[i]);

        while(m1.size()>x){
            m2.insert(*prev(m1.end()));
            m1.erase(prev(m1.end()));
        }

        vector<int>res;
        int ele = *prev(m1.end());
        res.push_back(ele>=0 ? 0 : ele);

        for(int i=k, j=0 ; i<nums.size() ; i++, j++)
        {
            if(m1.find(nums[j])!=m1.end())
            {
                m1.erase(m1.find(nums[j]));
                m2.insert(nums[i]);
                m1.insert(*m2.begin());
                m2.erase(m2.begin());
            }
            else
            {
                m2.erase(m2.find(nums[j]));
                m1.insert(nums[i]);
                m2.insert(*m1.rbegin());
                m1.erase(m1.find(*m1.rbegin()));
            }

            int ele = *prev(m1.end());
            res.push_back(ele>=0 ? 0 : ele);
        }

        return res;
    }
};