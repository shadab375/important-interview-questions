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

    int findMax(int num) {
        Node *cur = root;
        int ans=0;

        for (int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(cur->childs[!bit] != NULL) {
                cur = cur->childs[!bit];
                ans = ans | (1 << i);
            }
            else cur = cur->childs[bit];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> oq;

        int i = 0;
        for (auto &it: queries) oq.push_back({it[1], {it[0], i++}});

        sort (arr.begin(), arr.end());
        sort(oq.begin(), oq.end());

        int n = arr.size();
        int ind = 0;
        Trie trie;

        for (auto &it: oq) {
            int ai = it.first;
            int xi = it.second.first;
            int qInd = it.second.second;

            while (ind<n && arr[ind]<=ai) {
                trie.insert(arr[ind]);
                ind++;
            }

            if (ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.findMax(xi);
        }

        return ans;
    }
};