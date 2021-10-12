class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        int longest = 0;
        for (int num : nums) {
            if (s.find(num) == s.end()) {
                continue;
            }
            s.erase(num);
            int low = num - 1;
            int high = num + 1;
            while (s.find(low) != s.end()) {
                s.erase(low);
                low--;
            }
            while (s.find(high) != s.end()) {
                s.erase(high);
                high++;
            }
            longest = max(longest, high - low - 1);
        }
        return longest;
    }
};
