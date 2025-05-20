class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans, group(n + 1);

        for(int i = 0; i < n; ++i) {
            int size = groupSizes[i];
            group[size].push_back(i);

            if(group[size].size() == size) {
                ans.push_back({});
                swap(ans.back(), group[size]);
            }
        }

        return ans;
    }
};