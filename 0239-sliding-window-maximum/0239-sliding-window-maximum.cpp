class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n = nums.size();
        if(k == n) return {*max_element(nums.begin(), nums.end())};
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> p;
        
        cout<<*max_element(nums.begin(), nums.begin()+k);
        ans.push_back(*max_element(nums.begin(), nums.begin()+k));
        for(int i=0;i<k;i++) {
            p.push({nums[i], i});
        }
        if(k < n) {
            for(int i=k;i<n;i++) {
                mp[nums[i-k]] = i-k;
                p.push({nums[i], i});
                while(mp.find(p.top().first) != mp.end() and
                p.top().second <= i-k) {
                    p.pop();
                }
                ans.push_back(p.top().first);
            }
        }
        return ans;
    }
};