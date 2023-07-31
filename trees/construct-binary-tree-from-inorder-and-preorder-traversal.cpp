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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd, map<int, int>& inMap) {
        if (preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int i = inMap[root->val];
        int leftSize = i-inStart;

        root->left = build(preorder, inorder, inStart, i-1, preStart+1, preStart+leftSize, inMap);
        root->right = build(preorder, inorder, i+1, inEnd, preStart+leftSize+1, preEnd, inMap);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preStart = 0, preEnd = n-1;
        int inStart = 0, inEnd = n-1;

        map<int, int> inMap;
        for (int i=0; i<n; i++) inMap[inorder[i]] = i;

        TreeNode* root = build(preorder, inorder, inStart, inEnd, preStart, preEnd, inMap);
        return root;
    }
};