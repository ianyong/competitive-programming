class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> d;
        for (int i = 0; i < nums.size(); i++) {
            if (!d.empty() && i - k >= 0 && d.front() == nums[i - k]) {
                d.pop_front();
            }
            while (!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(d.front());
            }
        }
        return res;
    }
};
