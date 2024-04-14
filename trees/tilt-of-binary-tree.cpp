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
    int tilt = 0;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        tilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        solve(root);
        return tilt;
    }
};