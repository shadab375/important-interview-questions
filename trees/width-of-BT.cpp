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
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ll maxWidth = 0;

        while (!q.empty()) {
            ll size = q.size();
            ll left = q.front().second; //leftmost index
            ll right = q.back().second; //rightmost index
            maxWidth = max(maxWidth, right-left+1);
            for (int i=0; i<size; i++) {
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                ll index = it.second;
                if (node->left) q.push({node->left, 2*index+1});
                if (node->right) q.push({node->right, 2*index+2});
            }
        }
        return maxWidth;
    }
};