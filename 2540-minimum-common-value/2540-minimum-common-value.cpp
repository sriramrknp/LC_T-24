class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(nums2[n2-1] < nums1[0]) return -1;
        if(nums1[n1-1] < nums2[0]) return -1;
        
        if(nums2[n2-1] == nums1[0]) return nums1[0];
        if(nums1[n1-1] == nums2[0]) return nums2[0];
        int ans = -1;
        
        for(int i:nums2) {
            if(binary_search(nums1.begin(), nums1.end(), i)) {
                ans = i; break;
            }
        }
        return ans;
    }
};