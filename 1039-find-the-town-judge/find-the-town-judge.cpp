class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> edges(n + 1, 0);

        for(const auto& t : trust) {
            edges[t[0]]--;
            edges[t[1]]++;
        }

        // Now check judge condition
        for (int i = 1; i <= n; ++i) {
            if (edges[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};