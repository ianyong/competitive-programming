/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(unordered_map<int, Node*>& m, Node* node) {
        Node* newNode = new Node(node->val);
        m[node->val] = newNode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* neighbor = node->neighbors[i];
            if (m.find(neighbor->val) == m.end()) {
                dfs(m, neighbor);
            }
            newNode->neighbors.push_back(m[neighbor->val]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<int, Node*> m;
        dfs(m, node);
        return m[node->val];
    }
};
