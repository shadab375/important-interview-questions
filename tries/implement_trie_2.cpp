#include <bits/stdc++.h> 

struct Node {
    Node* childs[26];
    int cntStartWith = 0;
    int cntEndWith = 0;
};

class Trie{
private:
    Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* cur = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) cur->childs[ch-'a'] = new Node();
            cur = cur->childs[ch-'a'];
            cur->cntStartWith++;
        }
        
        cur->cntEndWith++;
    }

    int countWordsEqualTo(string &word){
        Node* cur = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) return 0;
            cur = cur->childs[ch-'a'];
        }

        return cur->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* cur = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) return 0;
            cur = cur->childs[ch-'a'];
        }

        return cur->cntStartWith;
    }

    void erase(string &word){
        Node* cur = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) return;
            cur = cur->childs[ch-'a'];
            cur->cntStartWith--;
        }

        cur->cntEndWith--;
    }
};
