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
    
    bool search(string word) {
        Node* cur = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            if (cur->childs[ch-'a'] == NULL) return false;
            cur = cur->childs[ch-'a'];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;

        for (int i=0; i<prefix.size(); i++) {
            char ch = prefix[i];
            if (cur->childs[ch-'a'] == NULL) return false;
            cur = cur->childs[ch-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */