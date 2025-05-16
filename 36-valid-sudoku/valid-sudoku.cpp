class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bitset<9>, 9> rows{}, cols{}, boxes{};

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if(rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                        return false;
                    }

                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }

        return true;
    }
};