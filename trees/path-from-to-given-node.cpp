/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Helper function to find the path from the root to a given target value 'x'
// in the binary tree. Returns true if the target value is found, and the path
// to the target is stored in the 'arr' vector.
bool getPath(TreeNode* root, vector<int>& arr, int x) {
    // If the current node is NULL, the target value 'x' is not present in the
    // current subtree, so we return false.
    if (root == NULL)
        return false;

    // Add the current node's value to the 'arr' vector, as it is part of the
    // current path being explored.
    arr.push_back(root->val);

    // If the current node's value is equal to the target value 'x', it means we
    // have found the target, and the path is complete. So, we return true.
    if (root->val == x)
        return true;

    // Otherwise, we recursively search for the target value 'x' in the left
    // and right subtrees of the current node.
    // If the target is found in either subtree, we return true to indicate that.
    if (getPath(root->left, arr, x))
        return true;
    if (getPath(root->right, arr, x))
        return true;

    // If the target value 'x' is not found in the current subtree, we backtrack
    // by removing the current node's value from the 'arr' vector, as it doesn't
    // belong to the path from the root to the target.
    arr.pop_back();

    // If the target value 'x' is not found in the current subtree or its children,
    // we return false to indicate that.
    return false;
}

// Main function to find the path from the root to the node with value 'x'
// in the binary tree. Returns a vector containing the path from the root to the
// target node.
vector<int> Solution::solve(TreeNode* root, int x) {
    // Create an empty vector to store the path to the target node 'x'.
    vector<int> arr;

    // If the root of the binary tree is NULL, the tree is empty, so we return
    // the empty 'arr' vector.
    if (root == NULL)
        return arr;

    // Call the helper function to find the path to the target value 'x' in the
    // binary tree. The path will be stored in the 'arr' vector.
    getPath(root, arr, x);

    // Return the 'arr' vector, which contains the path from the root to the node
    // with value 'x'.
    return arr;
}
