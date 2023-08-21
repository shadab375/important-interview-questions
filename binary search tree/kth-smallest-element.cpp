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

    void inorder(TreeNode* root, int k, int& ctr, int& ans) {
        if (!root) return;

        inorder(root->left, k, ctr, ans);
        ctr++;
        if (ctr == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ctr, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ctr = 0, ans = 0;
        inorder(root, k, ctr, ans);
        return ans;
    }
};