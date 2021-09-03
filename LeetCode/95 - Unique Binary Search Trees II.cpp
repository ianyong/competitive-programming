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
    vector<TreeNode*> generate(int left, int right) {
        if (left > right) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> trees;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftSubtree = generate(left, i - 1);
            vector<TreeNode*> rightSubtree = generate(i + 1, right);
            for (int j = 0; j < leftSubtree.size(); j++) {
                for (int k = 0; k < rightSubtree.size(); k++) {
                    trees.push_back(new TreeNode(i, leftSubtree[j], rightSubtree[k]));
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
