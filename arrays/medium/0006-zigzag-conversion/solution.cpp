class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> dp(numRows, "");
        if(numRows==1) return s;
        int row = 0;
        int inc = true;
        for(int i=0 ; i<s.size() ; i++){
            dp[row] += s[i];
            if(row<numRows-1 && inc){
                row++;
            }
            else if(row>0 && !inc){
                row--;
            }
            else{
                if(inc){
                    row--;
                    inc = false;
                }
                else{
                    row++;
                    inc = true;
                }
            }
        }

        string ans = "";
        for(int i=0 ; i<numRows ; i++){
            ans += dp[i];
        }

        return ans;
    }
};