class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        string sortedStr;
        for (int i = 0; i < strs.size(); i++) {
            sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            if (m.find(sortedStr) == m.end()) {
                m[sortedStr] = vector<string>();
            }
            m[sortedStr].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for (auto it = m.begin(); it != m.end(); it++) {
            v.push_back(it->second);
        }
        return v;
    }
};
