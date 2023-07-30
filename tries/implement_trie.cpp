
struct Node{
Node* childs[26];
bool isEnd = false;
};

class Trie {
public: Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (int i=0; i<word.length(); i++){
            char ch = word[i];
            if (curr -> childs[ch-'a'] == nullptr){
                curr -> childs[ch-'a'] = new Node();
            }
            curr = curr -> childs[ch-'a'];
        }
        curr -> isEnd = true;
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i=0; i<word.length(); i++){
            char ch = word[i];
            if (curr -> childs[ch-'a'] == nullptr){
                return false;
            }
            curr = curr -> childs[ch-'a'];
        }
        return curr -> isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i=0; i<prefix.length(); i++){
            char ch = prefix[i];
            if (curr -> childs[ch-'a'] == nullptr){
                return false;
            }
            curr = curr -> childs[ch-'a'];
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