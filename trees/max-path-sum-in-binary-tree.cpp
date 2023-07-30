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

    int solve(TreeNode* root, int& ans) {
        if (root == NULL) return 0;

        int leftMax = solve(root->left, ans);
        int rightMax = solve(root->right, ans);
        ans = max(ans, root->val + leftMax + rightMax);

        return max(0, root->val + max(leftMax, rightMax));
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};


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
    
    int pathsum(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }
        int left = max(0, pathsum(root->left,maxi));
        int right = max(0, pathsum(root->right,maxi));
        maxi = max (maxi, root->val+left+right);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi = INT_MIN;
        pathsum(root,maxi);
        return maxi;
    }
};