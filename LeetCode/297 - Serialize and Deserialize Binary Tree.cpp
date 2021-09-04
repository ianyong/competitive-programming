/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelper(ostringstream& o, TreeNode* node) {
        if (node == nullptr) {
            o << ',';
            return;
        }
        o << node->val << ',';
        serializeHelper(o, node->left);
        serializeHelper(o, node->right);
    }

    TreeNode* deserializeHelper(istringstream& i) {
        string s;
        getline(i, s, ',');
        if (s.size() == 0) {
            return nullptr;
        }
        int val = stoi(s);
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(i);
        node->right = deserializeHelper(i);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream o;
        serializeHelper(o, root);
        return o.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream i(data);
        return deserializeHelper(i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
