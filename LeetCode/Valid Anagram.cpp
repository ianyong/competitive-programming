class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int letters[26] = {};
        for (int i = 0; i < s.length(); i++) {
            letters[s[i] - 'a']++;
            letters[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (letters[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
