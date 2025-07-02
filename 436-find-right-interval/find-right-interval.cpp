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
        int n = intervals.size();
        vector<pair<int, int>> starts;
        starts.reserve(n);

        for(int i = 0; i < n; ++i) {
            starts.emplace_back(intervals[i][0], i);
        }

        sort(starts.begin(), starts.end());

        vector<int> result;
        result.reserve(n);

        for (const auto& interval : intervals) {
            int target = interval[1];

            // lower_bound to find first start >= target
            auto it = lower_bound(
                starts.begin(),
                starts.end(),
                make_pair(target, 0)
            );

            if (it == starts.end()) {
                result.push_back(-1);
            } else {
                result.push_back(it->second);
            }
        }

        return result;

    }
};