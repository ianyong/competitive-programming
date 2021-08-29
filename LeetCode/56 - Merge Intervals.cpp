class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) -> int {
           return v1[0] < v2[0];
        });
        v.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= v[v.size() - 1][1]) {
                v[v.size() - 1][1] = max(v[v.size() - 1][1], intervals[i][1]);
            } else {
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
