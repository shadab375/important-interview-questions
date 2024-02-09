class Solution {
public:

    void reverseInorder(TreeNode* root, int k, int& ctr, int& ans) {
        if (!root) return;

        reverseInorder(root->right, k, ctr, ans);
        ctr++;
        if (ctr == k) {
            ans = root->val;
            return;
        }
        reverseInorder(root->left, k, ctr, ans);
    }

    int kthLargest(TreeNode* root, int k) {
        int ctr = 0, ans = 0;
        reverseInorder(root, k, ctr, ans);
        return ans;
    }
};
