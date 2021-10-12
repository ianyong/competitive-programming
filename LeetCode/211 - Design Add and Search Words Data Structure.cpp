class WordDictionary {
private:
    class TrieNode {
        public:
            bool isWord;
            unordered_map<char, TrieNode*> children;
            TrieNode() {
                isWord = false;
            }
    };

    TrieNode* root;

    bool dfs(string& word, int i, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (i == word.size()) {
            return node->isWord;
        }
        char c = word[i];
        if (c == '.') {
            for (auto it = node->children.begin(); it != node->children.end(); it++) {
                if (dfs(word, i + 1, it->second)) {
                    return true;
                }
            }
            return false;
        }
        if (node->children.find(c) == node->children.end()) {
            return false;
        }
        return dfs(word, i + 1, node->children[c]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
