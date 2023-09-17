class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int ind = 0;
        for(int i=0;i<nums.size();i++) {
            if(temp[0] == nums[i]) {
                ind = i;
                break;
            }
        }
        int n = nums.size();
        for(int i=0;i<nums.size();i++) {
            if(nums[(ind+i)%n] != temp[i]) {
                return -1;
            }
        }
        return ind;
    }
};