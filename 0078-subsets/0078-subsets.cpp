class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        for(int i=0;i<(1<<n);i++){
            vector<int>row;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    row.push_back(nums[j]);
                }
            }
            res.push_back(row);
        }   
        return res;
    }
};