class Solution {
public:
    int characterReplacement(string s, int k) {
        int left, right, replaced, current, longest = 0;
        for (int i = 0; i < 26; i++) {
            left = right = replaced = 0;
            while (right < s.size()) {
                if (s[right] == 'A' + i) {
                    right++;
                } else if (replaced < k) {
                    right++;
                    replaced++;
                } else {
                    if (s[left] != 'A' + i) {
                        replaced--;
                    }
                    left++;
                }
                longest = max(longest, right - left);
            }
        }
        return longest;
    }
};
