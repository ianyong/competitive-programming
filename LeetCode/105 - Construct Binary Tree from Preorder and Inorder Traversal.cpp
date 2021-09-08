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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& m, int& preorderIndex, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int root = m[preorder[preorderIndex++]];
        TreeNode* node = new TreeNode(inorder[root]);
        node->left = buildTree(preorder, inorder, m, preorderIndex, left, root - 1);
        node->right = buildTree(preorder, inorder, m, preorderIndex, root + 1, right);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        int preorderIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, m, preorderIndex, 0, preorder.size() - 1);
    }
};
