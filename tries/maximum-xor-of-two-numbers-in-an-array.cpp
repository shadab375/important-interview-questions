struct Node{
	Node* childs[2];
};

class Trie {
private: 
    Node *root = new Node();
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node *cur = root;

        for (int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(cur->childs[bit] == NULL) cur->childs[bit] = new Node();
            cur = cur->childs[bit];
        }
    }

    int maxXor(int num) {
        Node *cur = root;
        int ans=0;

        for (int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(cur->childs[!bit] != NULL) {
                ans = ans | (1 << i);
                cur = cur->childs[!bit];
            }
            else cur = cur->childs[bit];
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans = 0;
        for (auto &it:nums) trie.insert(it);
        for (auto &it:nums) ans = max(ans, trie.maxXor(it));
        return ans; 
    }
};