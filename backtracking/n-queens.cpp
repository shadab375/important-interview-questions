class Solution {
public:
    vector<vector<string>> result;
    int n;

    bool isValid(vector<string>& board, int row, int col) {
        for (int i=row-1; i>=0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board) {
        if (row >= n) {
            result.push_back(board);
            return;
        }

        for (int col=0; col<n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                solve(row+1, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return result;
    }
};