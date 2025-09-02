class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        int ans = 0;
        long long m = 1;
        while(n>=m){
            long long high = n / (m * 10);
            long long curr = (n / m) % 10;
            long long low = n % m;

            if(curr==0){
                ans += high * m;
            }
            else if(curr==1){
                ans += high * m + (low + 1);
            }
            else{
                ans += (high + 1) * m;
            }

            m *= 10;
        }

        return ans;
    }
};