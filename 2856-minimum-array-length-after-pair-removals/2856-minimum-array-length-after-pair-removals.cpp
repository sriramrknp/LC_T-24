class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int temp = 1;
        int maxi = INT_MIN;
        for(int i=1;i<n;i++) {
            if(nums[i] == nums[i-1]) {
                temp++;
            } else {
                maxi = max(temp, maxi);
                temp = 1;
            }
        }
        maxi = max(temp, maxi);

        if(maxi <= n/2) {
            return n%2;
        }
        return 2*maxi - n;
    }
};