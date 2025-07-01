class Solution {
public:
    struct Comparator {
        int k;
        Comparator(int col) : k(col) {}
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[k] > b[k];
        }
    };

    vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {
        sort(v.begin(), v.end(), Comparator(k));

        return v;
    }
};