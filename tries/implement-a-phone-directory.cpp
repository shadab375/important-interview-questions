struct Node {
    Node* childs[26];
    bool isEnd = false;
};

void storeAllSuggestions(vector<string>& temp, Node* cur, string prefix) {
    if (cur->isEnd == true) temp.push_back(prefix);

    for (char ch='a'; ch<='z'; ch++) {
        if (cur->childs[ch-'a'] != NULL) {
            prefix.push_back(ch);
            storeAllSuggestions(temp, cur->childs[ch-'a'], prefix);
            prefix.pop_back();
        }
    }
}
 
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

    vector<vector<string>> getSuggestions(string str) {
        vector<vector<string>> ans;
        Node* prev = root;
        string prefix = "";

        for (int i=0; i<str.size(); i++) {
            char ch = str[i];
            prefix.push_back(ch);

            Node* cur = prev->childs[ch-'a'];
            if (cur == NULL) break;

            vector<string> temp;
            storeAllSuggestions(temp, cur, prefix);
            ans.push_back(temp);
            temp.clear();

            prev = cur;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie trie;
    for (auto &it: contactList) trie.insert(it);
    return trie.getSuggestions(queryStr);
}