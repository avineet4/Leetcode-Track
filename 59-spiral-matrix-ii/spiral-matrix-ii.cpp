class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int num = 1;

        while (top<=bottom && left<=right) {
            for (int i = left; i <= right; i++) {
                result[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result[i][right] = num++;
            }
            right--;

            if (bottom < top) {
                break;
            }

            for (int i = right; i >= left; i--) {
                result[bottom][i] = num++;
            }
            bottom--;

            if(right < left) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                result[i][left] = num++;
            }
            left++;
        }

        return result;
    }
};