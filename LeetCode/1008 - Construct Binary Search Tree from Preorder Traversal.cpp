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
    TreeNode* constructBst(vector<int>& preorder, int& i, int upperLimit) {
        if (i == preorder.size()) {
            return nullptr;
        }
        if (preorder[i] > upperLimit) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = constructBst(preorder, i, node->val);
        node->right = constructBst(preorder, i, upperLimit);
        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return constructBst(preorder, index, INT_MAX);
    }
};
