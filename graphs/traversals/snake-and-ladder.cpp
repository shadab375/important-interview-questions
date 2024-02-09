class Solution {
public:
    int n;

    pair<int, int> getCord(int num) {
        int RT = (num - 1) / n;
        int RB = (n - 1) - RT;

        int col = (num - 1) % n;
        if ((n % 2 == 0 && RB % 2 == 0) || (n % 2 == 1 && RB % 2 == 1)) {
            col = (n - 1) - col;
        }

        return make_pair(RB, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<int> q;
        int steps = 0;

        q.push(1);
        visited[n-1][0] = 1;

        while (!q.empty()) {
            int N = q.size();

            while (N--) {
                int pos = q.front();
                q.pop();
                if (pos == n * n) return steps;

                for (int k=1; k<=6; k++) {
                    int npos = pos + k;
                    if (npos > n * n) break;

                    pair<int, int> cord = getCord(npos);
                    int nr = cord.first;
                    int nc = cord.second;

                    if (visited[nr][nc]) continue;
                    visited[nr][nc] = 1;

                    if (board[nr][nc] == -1) q.push(npos);
                    else q.push(board[nr][nc]);
                }
            }

            steps++;
       }

       return -1;
    }
};