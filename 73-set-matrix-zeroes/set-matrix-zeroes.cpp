class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        set<int> row;
        set<int> col;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i = 0; i < rows; ++i) {
            if(row.find(i) != row.end()) {
                for(int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < cols; ++i) {
            if(col.find(i) != col.end()) {
                for(int j = 0; j < rows; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }

    }
};