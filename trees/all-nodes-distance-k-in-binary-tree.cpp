/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;
        int cur_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (cur_level == k) break;
            cur_level++;

            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};