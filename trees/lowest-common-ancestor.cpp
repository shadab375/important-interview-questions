//clean code without comments
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool getPath(TreeNode* root, vector<int>& arr, int x) {
    if (root == NULL) return false;
    
    arr.push_back(root->val);
    if (root->val == x) return true;   
    if (getPath(root->left, arr, x)) return true;
    if (getPath(root->right, arr, x)) return true;
    arr.pop_back();
    
    return false;
}

vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int> arr;
    if (root == NULL) return arr;
    getPath(root, arr, x);
    return arr;
}

//code with explanation by comments
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Function to find the lowest common ancestor of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the current node is NULL or one of the target nodes (p or q),
        // it is a potential lowest common ancestor.
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recursively find the lowest common ancestor in the left subtree
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Recursively find the lowest common ancestor in the right subtree
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If one of the subtrees returned NULL, it means both p and q are present
        // in the other subtree, and the LCA must be in that subtree.
        if (leftLCA == NULL) {
            return rightLCA;
        }
        if (rightLCA == NULL) {
            return leftLCA;
        }

        // If both leftLCA and rightLCA are not NULL, it means p and q are found
        // in different subtrees of the current root node. So, the current root node
        // is the lowest common ancestor.
        return root;
    }
};


