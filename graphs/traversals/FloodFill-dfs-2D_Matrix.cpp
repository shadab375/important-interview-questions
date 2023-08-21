#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;

    void dfs(int x, int y, vector<vector<int>>& ans, vector<vector<int>>& image, int initialColor, int newColor) {
        ans[x][y] = newColor;

        for (auto &dir: directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];

            auto isSafe = [&](int x, int y) {
                return x>=0 && x<n && y>=0 && y<m;
            };

            if (isSafe(new_x, new_y) && image[new_x][new_y] == initialColor && ans[new_x][new_y] != newColor) {
                dfs(new_x, new_y, ans, image, initialColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        dfs(sr, sc, ans, image, initialColor, newColor);
        return ans;
    }
};