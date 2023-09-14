class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix, suffix;
        int maxval = INT_MIN;
        for(auto i:height) {
            maxval = max(maxval, i);
            prefix.push_back(maxval);
        }
        maxval = INT_MIN;
        for (auto it = height.rbegin(); it != height.rend(); ++it) {
            maxval = max(maxval, *it);
            suffix.push_back(maxval);
        }
        reverse(suffix.begin(), suffix.end());
        int ans = 0;
        for(int i=0;i<height.size();i++) {
            ans += min(prefix[i], suffix[i]) - height[i];
        }
        return ans;
    }
};