class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> subgridSet;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !rowSet.insert(board[i][j]).second)
                return false;

                if (board[j][i] != '.' && !colSet.insert(board[j][i]).second)
                return false;

                int subgridRow = 3 * (i / 3) + j / 3;
                int subgridCol = 3 * (i % 3) + j % 3;
                if (board[subgridRow][subgridCol] != '.' && !subgridSet.insert(board[subgridRow][subgridCol]).second)
                return false;
            }
        }
        return true;
    }
};
