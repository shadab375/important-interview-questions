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

class Solution {
public:

    void traversal(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        
        for (auto& node: root->children) {
            traversal(node, ans);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};