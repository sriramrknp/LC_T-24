typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define PB push_back
#define POPB pop_back

class Solution {
    vi setProcess;
    void takeOrNotTake(vi nums, int i, vvi& ans, int n) {
        if(i >= n) {
            ans.PB(setProcess);
            return;
        }
        takeOrNotTake(nums, i+1, ans, n);
        setProcess.PB(nums[i]);
        takeOrNotTake(nums, i+1, ans, n);
        setProcess.POPB();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi ans;
        takeOrNotTake(nums, 0, ans, nums.size());
        return ans;
    }
};