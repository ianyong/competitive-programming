class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) -> bool {
            return v1[1] < v2[1];
        });
        int erased = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                erased++;
                continue;
            }
            last = intervals[i][1];
        }
        return erased;
    }
};
