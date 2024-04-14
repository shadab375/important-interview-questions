class Solution {
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;

    bool find(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if (idx >= word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx] || board[i][j] == '$') return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for (auto &dir: directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (find(ni, nj, idx+1, board, word)) return true;
        }
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == word[0] && find(i, j, 0, board, word)) return true;
            }
        }

        return false;
    }
};