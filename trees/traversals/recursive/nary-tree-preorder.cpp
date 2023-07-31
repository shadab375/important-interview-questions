/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void traversal(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);
        for (auto node: root->children) {
            traversal(node, ans);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};