class Solution {
public:
    // static bool compare(pair<int, int>& a, pair<int, int>& b) {
    //     return a.first < b.first;
    // }

    int search(vector<pair<int, int>>& arr, int target) {
        int left = 0, right = arr.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(arr[mid].first == target) {
                return arr[mid].second;
            } else if(arr[mid].first < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (left < arr.size()) ? arr[left].second : -1;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts;

        for(int i = 0; i < intervals.size(); ++i) {
            starts.push_back(pair<int, int>(intervals[i][0], i));
        }

        sort(starts.begin(), starts.end());

        vector<int> result;
        result.reserve(intervals.size());

        for(const auto& interval : intervals) {
            result.push_back(search(starts, interval[1]));
        }

        return result;

    }
};