class Solution {
public:
    bool isPossible(vector<int> &position, int mid, int m){
        int place = position[0];
        m--;
        for(int i=1 ; i<position.size() ; i++){
            if(position[i]>=place+mid){
                place = position[i];
                m--;
            }
            if(m==0) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = 1e9;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(position,mid,m)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};