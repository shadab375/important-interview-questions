//CLEAN CODE
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool hasPath(TreeNode *root, vector<int>& arr, int x) {
    if (!root) return false;

    arr.push_back(root->val);
    if (root->val == x) return true;
    if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x)) return true;
    arr.pop_back();
    
    return false;
}

vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int> ans;
    hasPath(root, ans, x);
    return ans;
}

//CODE WITH COMMENTS
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Returns true if there is a path from root
// to the given node. It also populates
// 'arr' with the given path
bool hasPath(TreeNode *root, vector<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    arr.push_back(root->val);

    // if it is the required node
    // return true
    if (root->val == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false
    arr.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    hasPath(A,ans,B);
    return ans;
}