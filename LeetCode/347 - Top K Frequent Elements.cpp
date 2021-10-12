class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
        }

        vector<vector<int> > v(nums.size(), vector<int>());
        for (auto it = m.begin(); it != m.end(); it++) {
            v[it->second - 1].push_back(it->first);
        }

        vector<int> res;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (res.size() >= k) {
                break;
            }
            for (int j = 0; j < v[i].size(); j++) {
                res.push_back(v[i][j]);
            }
        }
        return res;
    }
};
