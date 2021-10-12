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
    TreeNode* findSubtree(TreeNode* node, TreeNode* subRoot) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val == subRoot->val) {
            return node;
        }
        TreeNode* left = findSubtree(node->left, subRoot);
        if (left != nullptr) {
            return left;
        }
        return findSubtree(node->right, subRoot);
    }

    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        TreeNode* node = findSubtree(root, subRoot);
        if (isSameTree(node, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
