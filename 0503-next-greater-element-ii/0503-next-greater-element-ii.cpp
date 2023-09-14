class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        vector<int> ans;
        stack<int> qu;
        for(int i=0;i<nums2.size()-1;i++) {
            if(nums2[i] > nums2[nums2.size()-1]) {
                qu.push(nums2[i]);
                break;
            }
        }

        for(int i=nums2.size()-1;i>=0;i--) {
            if(!qu.empty() and qu.top() > nums2[i]) {
                ans.push_back(qu.top());
            } else {
                while(!qu.empty() and qu.top() <= nums2[i]) {
                    qu.pop();
                }
                if(qu.empty()) {
                    for(int j=0;j<i;j++) {
                        if(nums2[j] > nums2[i]) {
                            qu.push(nums2[j]);
                            ans.push_back(qu.top());
                            break;
                        }
                    }
                    if(qu.empty())
                        ans.push_back(-1);
                }
                else ans.push_back(qu.top());
            }
            qu.push(nums2[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};