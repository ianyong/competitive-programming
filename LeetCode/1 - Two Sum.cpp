class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int diff;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if (m.find(diff) != m.end()) {
                return vector<int>{m[diff], i};
            }
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};
