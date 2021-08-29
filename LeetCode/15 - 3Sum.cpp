class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int j, k, sum;
        for (int i = 2; i < nums.size(); i++) {
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
            j = 0;
            k = i - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    triplets.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    do {
                        j++;
                    } while (j < k && nums[j] == nums[j - 1]);
                    continue;
                }
                if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return triplets;
    }
};
