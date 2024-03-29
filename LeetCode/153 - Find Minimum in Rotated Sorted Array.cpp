class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            if (nums[low] < nums[high]) {
                return nums[low];
            }
            mid = low + (high - low) / 2;
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};
