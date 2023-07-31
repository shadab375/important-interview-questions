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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, map<int, int>& inMap) {
        if (inStart>inEnd || postStart>postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int i = inMap[root->val];
        int leftSize = i-inStart;

        root->left = build(inorder, postorder, inStart, i-1, postStart, postStart+leftSize-1, inMap);
        root->right = build(inorder, postorder, i+1, inEnd, postStart+leftSize, postEnd-1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0, inEnd = n-1;
        int postStart = 0, postEnd = n-1;

        map<int, int> inMap;
        for (int i=0; i<n; i++) inMap[inorder[i]] = i;
        
        TreeNode* root = build(inorder, postorder, inStart, inEnd, postStart, postEnd, inMap);
        return root;
    }
};
