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

    bool isBST(TreeNode* root, long mini, long maxi) {
        if (!root) return true;
        if (root->val >= maxi || root->val <= mini) return false;

        bool left = isBST(root->left, mini, root->val);
        bool right = isBST(root->right, root->val, maxi);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};