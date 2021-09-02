class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited = vector<bool>(nums.size(), false);
        int longest = 0;
        int curr;
        for (int i = 0, j = i; i < nums.size(); j = ++i) {
            curr = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                curr++;
            }
            longest = max(longest, curr);
        }
        return longest;
    }
};
