class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int currentOne = 1;
        int currentTwo = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                currentOne = 1;
                currentTwo = 0;
                largest = max(largest, 0);
                continue;
            }
            currentOne *= nums[i];
            currentTwo *= nums[i];
            largest = max(largest, currentOne);
            if (currentTwo != 0) {
                largest = max(largest, currentTwo);
            }
            if (currentTwo == 0 && nums[i] < 0) {
                currentTwo = 1;
            }
        }
        return largest;
    }
};
