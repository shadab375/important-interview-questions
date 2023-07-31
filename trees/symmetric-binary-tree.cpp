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

    bool issym(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) return left == right;

        return (left->val == right->val) &&
              (issym(left->right, right->left)) &&
              (issym(left->left, right->right));
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return issym(root->left, root->right);
    }
};