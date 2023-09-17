class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = nums[0];
        int ans = 0, i;
        int n = nums.size();
        if(n >= 2) {
            if(nums[0] > 0) ans = 1;
        }
        for(i=0;i<nums.size()-1;i++) {
            if(((i+1) > nums[i]) and ((i+1) < nums[i+1])) {
                ans++;
            }
        }
        if(i+1 > nums[i]) {
            ans++;
        }
        return ans;
    }
};