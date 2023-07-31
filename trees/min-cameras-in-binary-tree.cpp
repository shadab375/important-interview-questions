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

    int cameras = 0;
    int minCamerasInBT(TreeNode* root) {
        if (root == NULL) return 1;
        
        int lchild = minCamerasInBT(root->left);
        int rchild = minCamerasInBT(root->right);

        if (lchild == -1 || rchild == -1) {
            cameras++;
            return 0;
        }
        if (lchild == 0 || rchild == 0) return 1;
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if (minCamerasInBT(root) == -1) cameras++;
        return cameras;
    }
};