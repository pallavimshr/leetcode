class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // rows[row][num] tells us whether
        // 'num' has already appeared in this row
        bool rows[9][10] = {};

        // cols[col][num] tells us whether
        // 'num' has already appeared in this column
        bool cols[9][10] = {};

        // boxes[box][num] tells us whether
        // 'num' has already appeared in this 3x3 box
        bool boxes[9][10] = {};

        // Visit every cell
        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                // Ignore empty cells
                if (board[row][col] == '.') {
                    continue;
                }

                // Convert character '5' to integer 5
                int num = board[row][col] - '0';

                // Find which 3x3 box this cell belongs to
                int box = (row / 3) * 3 + (col / 3);

                // If number already exists in row,
                // column or box → invalid Sudoku
                if (rows[row][num] ||
                    cols[col][num] ||
                    boxes[box][num]) {

                    return false;
                }

                // Mark number as seen
                rows[row][num] = true;
                cols[col][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};