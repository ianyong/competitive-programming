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
private:
    int maxPathFromRoot(int& res, TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, maxPathFromRoot(res, root->left));
        int right = max(0, maxPathFromRoot(res, root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathFromRoot(res, root);
        return res;
    }
};
