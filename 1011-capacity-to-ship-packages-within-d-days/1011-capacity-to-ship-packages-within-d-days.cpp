class Solution {
public:
    bool feasible(vector<int>& weights, int days, int cap) {
        int d = 1, w = 0;
        for(int i=0;i<weights.size();i++) {
            w += weights[i];
            if(w > cap) {
                d++;
                if(d > days) return false;
                w = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minc = *max_element(weights.begin(), weights.end());
        int maxc = accumulate(weights.begin(), weights.end(), 0);
        // cout<<minc<<" "<<maxc;
        int cap = minc + (maxc - minc)/2;
        while(minc < maxc) {
            if(feasible(weights, days, cap)) {
                maxc = cap;
            } else minc = cap+1;
            cap = minc + (maxc - minc)/2;
        }
        return minc;
    }
};