#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;
        q.push({beginWord});

        while (!q.empty()) {
            int size = q.size();
            vector<string> wordsUsed;

            for (int i=0; i<size; i++) {
                vector<string> path = q.front();
                string word = q.front().back();
                q.pop();

                if (word == endWord) {
                    ans.push_back(path);
                    continue;
                }

                for (int i=0; i<word.size(); i++) {
                    char original = word[i];
                    for (char ch='a'; ch<='z'; ch++) {
                        word[i] = ch;
                        if (st.find(word) != st.end()) {
                            path.push_back(word);
                            q.push(path);
                            wordsUsed.push_back(word);
                            path.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }

            for (auto it: wordsUsed) st.erase(it);
        }

        return ans;
    }
};