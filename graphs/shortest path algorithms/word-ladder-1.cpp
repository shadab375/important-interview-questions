#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        
        q.push({startWord, 1});
        st.erase(startWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord) return steps;

            for (int i=0; i<word.size(); i++) {
                char original = word[i];
                for (int ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};