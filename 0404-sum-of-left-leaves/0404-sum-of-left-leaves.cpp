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
    void leftLeaves(TreeNode* root, int& count) {
        if(root == nullptr) return;

        if(root->left != nullptr) {
            if(root->left->left == nullptr and 
            root->left->right == nullptr) {
                count += root->left->val;
            }
        }
        leftLeaves(root->left, count);
        leftLeaves(root->right, count);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        leftLeaves(root, ans);
        return ans;
    }
};