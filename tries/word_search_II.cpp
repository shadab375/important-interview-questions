#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isEnd = false;
    Node* childs[26];
    string word;
};

class Trie{
    public: Node* root;
    Trie(){
        root=new Node();
    }
    
    void insert(string word){
        Node* curr = root;
        for (int i=0; i<word.size(); i++){
            char ch = word[i];
            if (curr -> childs[ch - 'a'] == NULL) {
                curr -> childs[ch-'a'] = new Node();
            }
            curr = curr -> childs[ch - 'a'];
        }
        curr -> isEnd = true;
        curr -> word = word;
    }
    
    void search(vector<vector<char>> &board, Node* temp,int i,int j,vector<string>
    &ans){
	//temp is the current node in the trie.
	// (i,j) is the current cell in the grid.
        if (i<0 || j<0 || i==board.size() || j==board[0].size() ||
        board[i][j]=='*' || temp -> childs[board[i][j] - 'a'] == NULL) return;
        temp = temp -> childs[board[i][j] - 'a'];
        if(temp->isEnd == true) {
            ans.push_back(temp->word);
            temp->isEnd = false;
        }
        char ch=board[i][j];
        board[i][j] = '$'; //preventing this from getting reconsidered in same word
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        for (int ind=0; ind<4; ind++){
            int new_i = i + di[ind];
            int new_j = j + dj[ind];
            search(board, temp, new_i, new_j, ans);
        }
        board[i][j]=ch; //restoring original character
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string s:words) trie.insert(s);
        vector<string> ans;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                trie.search(board,trie.root,i,j,ans);
        return ans;
    }
};