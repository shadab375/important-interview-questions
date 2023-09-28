#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* childs[26];
    bool isEnd = false;
};

int countDistinctSubstrings(string &word) {
    int n = word.size();
    int cnt = 0;
    Node* root = new Node();

    for (int i=0; i<n; i++) {
        Node* cur = root;

        for (int j=i; j<n; j++) {
            char ch = word[j];

            if (cur->childs[ch-'a'] == NULL) {
                cur->childs[ch-'a'] = new Node();
                cnt++;
            }
            
            cur = cur->childs[ch-'a'];
        }
    }

    return cnt+1;
}