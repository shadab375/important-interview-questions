class TreeAncestor {
public:
    vector<vector<int>> table;

    TreeAncestor(int n, vector<int>& parent) {
        table.resize(17, vector<int>(parent.size(), -1));
        
        for (int i=0; i<parent.size(); i++) {
            table[0][i] = parent[i];
        }

        for (int i=1; i<17; i++) {
            for (int j=0; j<parent.size(); j++) {
                if (table[i-1][j] != -1) table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i=0; i<17; i++) {
            if (k & (1<<i)) {
                node = table[i][node];
                if (node == -1) return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */