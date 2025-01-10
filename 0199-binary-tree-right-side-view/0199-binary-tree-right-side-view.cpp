/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void rightView(TreeNode* root, vector<int>& ans, int count) {
        if(root == nullptr) return;

        if(count > ans.size()) {
            ans.push_back(root->val);
        }

        rightView(root->right, ans, count+1);
        rightView(root->left, ans, count+1);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> ans;

        rightView(root, ans, 1);

        return ans;
    }
};