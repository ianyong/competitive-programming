class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        int uniqueChars = m.size();
        int left = 0;
        int right = 0;
        int shortest = INT_MAX;
        int shortestStart = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[right]) != m.end() && --m[s[right]] == 0) {
                uniqueChars--;
            }
            right++;
            while (uniqueChars == 0) {
                if (right - left < shortest) {
                    shortest = right - left;
                    shortestStart = left;
                }
                if (m.find(s[left]) != m.end() && m[s[left]]++ == 0) {
                    uniqueChars++;
                }
                left++;
            }
        }
        if (shortest == INT_MAX) {
            return "";
        }
        return s.substr(shortestStart, shortest);
    }
};
