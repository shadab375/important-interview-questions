#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool searchNext(vector<vector<char>> &board, string word, int i, int j, 
    int index, int n, int m) {

        // if index reaches at the end that means we have found the word
        if (index == word.length())
            return true;

        // Checking the boundaries if the character at which we are placed is not 
        //the required character
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != 
        word[index] or board[i][j] == '$')
            return false;

        // this is to prevent reusing of the same character
        char ch = board[i][j];
        board[i][j] = '$'; //preventing this from getting reconsidered in same word

        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        for (int ind=0; ind<4; ind++){
            int new_i = i + di[ind];
            int new_j = j + dj[ind];
            if (searchNext(board, word, new_i, new_j, index+1, n, m)) return true;
        }

        board[i][j] = ch; // undo change
        return false;
    }
    bool exist(vector<vector<char>> board, string word) {

        int n = board.size();
        int m = board[0].size();

        int index = 0;

        // First search the first character
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[index] && searchNext(board, word, i, j, index, n, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};