class Solution {
private:
    int countByExpanding(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            count += countByExpanding(s, i, i);
            count += countByExpanding(s, i - 1, i);
        }
        return count;
    }
};
