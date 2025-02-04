typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define PB push_back
#define POPB pop_back
#define sze nums.size()

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi ans;
        int n = sze;
        // Another way to generate subsets is based on the 
        // bit representation of integers.
        // Each subset of a set of n elements can be 
        // represented as a sequence of n bits,
        // which corresponds to an integer between 0...2n − 1. 
        // The ones in the bit sequence
        // indicate which elements are included in the subset.
        for (int b = 0; b < (1<<n); b++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (b&(1<<i)) subset.PB(nums[i]);
            }
            ans.PB(subset);
        }
        return ans;
    }
};