class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = INT_MIN;
        int current = 0;
        for (int i = 0; i < nums.size(); i++) {
            current += nums[i];
            largest = max(largest, current);
            current = max(0, current);
        }
        return largest;
    }
};
