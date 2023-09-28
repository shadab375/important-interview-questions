#include <bits/stdc++.h> 
using namespace std;

struct Node {
    Node* childs[26];
    bool isEnd = false;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;
        
        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) cur->childs[ch-'a'] = new Node();
            cur = cur->childs[ch-'a'];
        }

        cur->isEnd = true;
    }

    bool checkForPrefixes(string word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch - 'a'] == NULL) return false;
            else {
                cur = cur->childs[ch - 'a'];
                if (cur->isEnd == false) return false;
            }
        }

        return true;
    }
};



string completeString(int n, vector<string> &a){
    Trie trie;
    for (auto&it: a) trie.insert(it);

    string longest = "";

    for (auto &it: a) {
        if (trie.checkForPrefixes(it)) {
            if (it.length() > longest.length()) longest = it;
            else if (it.length() == longest.length() && it < longest) longest = it;
        }
    }

    if (longest == "") return "None";
    return longest;
}