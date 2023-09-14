class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        priority_queue <int, vector<int>, greater<int>> qu;
        qu.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-1;i>=0;i--) {
            if(qu.top() > nums2[i]) {
                mp[nums2[i]] = qu.top();
            } else {
                while(!qu.empty() and qu.top() <= nums2[i]) {
                    qu.pop();
                }
                if(qu.empty()) mp[nums2[i]] = -1;
                else mp[nums2[i]] = qu.top();
            }
            cout<<nums2[i]<<" "<<mp[nums2[i]]<<endl;
            qu.push(nums2[i]);
        }
        for(auto i:nums1) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};