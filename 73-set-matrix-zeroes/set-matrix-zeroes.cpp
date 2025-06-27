class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool isFirstRow = false;
        bool isFirstCol = false;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0) isFirstRow = true;
                    else matrix[i][0] = 0;

                    if(j == 0) isFirstCol = true;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; ++i) {
            for(int j = 1; j < cols; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(isFirstRow) {
            for(int i = 0; i < cols; ++i) {
                matrix[0][i] = 0;
            }
        }

        if(isFirstCol) {
            for(int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};