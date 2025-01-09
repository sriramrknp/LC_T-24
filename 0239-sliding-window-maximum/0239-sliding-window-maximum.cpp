class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) {
            return nums;
        }
        deque<int> dq;
        dq.push_back(0);

        for(int i=1;i<k;i++) {
            while(!dq.empty() and nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++) {
            while(!dq.empty() and dq.front() < (i-k+1)) dq.pop_front();

            while(!dq.empty() and nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};