class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int prevEnd = INT_MIN;
        int count = 0;

        for(const auto& interval: intervals) {
            if(interval[0] < prevEnd) {
                count++;
            } else {
                prevEnd = interval[1];
            }
        }

        return count;
    }
};