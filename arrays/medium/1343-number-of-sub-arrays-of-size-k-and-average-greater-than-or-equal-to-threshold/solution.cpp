class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        double windowSum = 0;
        for(int i=0 ; i<k ; i++){
            windowSum += arr[i];
        }

        int ans = windowSum/k >= threshold ? 1 : 0;

        for(int i=k ; i<n ; i++){
            windowSum += arr[i];
            windowSum -= arr[i-k];
            ans += windowSum/k >= threshold ? 1 : 0;
        }

        return ans;
    }
};