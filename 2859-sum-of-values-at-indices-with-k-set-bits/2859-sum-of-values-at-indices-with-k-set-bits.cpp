class Solution {
public:
    int bits(int n) {
        int count = 0;
        while(n>0) {
            count += n&1;
            n = n>>1;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(bits(i) == k)
                count += nums[i];
        }
        return count;
    }
};