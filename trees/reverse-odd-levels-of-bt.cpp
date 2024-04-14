/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left), level.push_back(node->left->val);
                if (node->right) q.push(node->right), level.push_back(node->right->val);
            }

            if (odd) {
                reverse(level.begin(), level.end());
                n = q.size();
                int i = 0;

                while (n--) {
                        TreeNode* node = q.front();
                        q.pop();
                        node->val = level[i++];
                        q.push(node);
                    }
                }
                
                odd = !odd;
            }

        return root;
    }
};