class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2%2 == 0 and n1%2 == 1) return xorAllNums(nums2, nums1);

        if(n2%2 == 0 and n1%2 == 0) return 0;
        else if((n1%2 == 0 and n2%2 == 1)) {
            int ans = 0;
            for(int i:nums1) ans ^= i;
            return ans;
        }
        int ans = 0;
        for(int i:nums1) ans ^= i;
        for(int i:nums2) ans ^= i;
        return ans;
    }
};