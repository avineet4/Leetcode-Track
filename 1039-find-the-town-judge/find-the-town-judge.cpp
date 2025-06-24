class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inEdge(n + 1, 0), outEdge(n + 1, 0);

        for(const auto& t : trust) {
            outEdge[t[0]]++;
            inEdge[t[1]]++;
        }

        // Now check judge condition
        for (int i = 1; i <= n; ++i) {
            if (outEdge[i] == 0  && inEdge[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};