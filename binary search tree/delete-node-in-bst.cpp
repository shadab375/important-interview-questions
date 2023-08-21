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

    TreeNode* findMax(TreeNode* root) {
        if (!root) return NULL;

        TreeNode* cur = root;
        while (cur->right) cur = cur->right;
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key > root->val) root->right = deleteNode(root->right, key);
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else {
                TreeNode* temp = findMax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }

        return root;
    }
};