class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {
        sort(v.begin(), v.end(),[k](auto& a, auto& b) { 
            return a[k] > b[k]; 
        });

        return v;
    }
};