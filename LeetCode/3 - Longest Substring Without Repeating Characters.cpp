class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int longest = 0;
        unordered_set<char> duplicates;
        char c;
        for (int i = 0; i < s.size(); i++) {
            if (duplicates.find(s[i]) != duplicates.end()) {
                while ((c = s[start++]) != s[i]) {
                    duplicates.erase(c);
                }
            }
            duplicates.insert(s[i]);
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};
