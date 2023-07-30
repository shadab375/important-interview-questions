#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        map<int, map<int, vector<int>>> nodes;
        //{verticalIndex, level} -> array, sorted by verticalIndex 
        queue<pair<TreeNode*, pair<int, int>>> q;
        //{node, {verticalIndex, level}}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int verticalIndex = it.second.first, level = it.second.second;
            nodes[verticalIndex][level].push_back(node->val);

            if (node->left) q.push({node->left, {verticalIndex-1, level+1}});
            if (node->right) q.push({node->right, {verticalIndex+1, level+1}});
        }

        for (auto x: nodes) {
            vector<int> col;
            for (auto y: x.second) {
                sort(y.second.begin(), y.second.end());
                for (int val: y.second) col.push_back(val);
            }
            ans.push_back(col);
        }
        return ans;
    }
};