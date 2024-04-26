class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });
        int removals = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev[1]) {
                removals++;
            } else {
                prev = intervals[i];
            }
        }
        return removals;
    }
};
