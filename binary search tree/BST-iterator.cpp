//USING ITERATIVE INORDER TRAVERSAL
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
class BSTIterator {
public:
    stack<TreeNode*>st;

    void pushAll(TreeNode* node){
        for(;node!=NULL;st.push(node),node=node->left);
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//USING MORRIS TRAVERSAL
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
class BSTIterator {
private:
    TreeNode* cur = NULL;

    TreeNode* getRightMostNode(TreeNode* rmn) {
        while (rmn->right!=NULL && rmn->right != this->cur) {
            rmn = rmn->right;
        }
        return rmn;
    }

    TreeNode* morrisTraversal() {
        TreeNode* res = NULL;

        while (this->cur != NULL) {
            TreeNode* leftNode = this->cur->left;

            if (leftNode == NULL) {
                res = this->cur;
                cur = this->cur->right;
                break;
            }
            else {
                TreeNode* rightMostNode = getRightMostNode(leftNode);

                if (rightMostNode->right == NULL) {
                    rightMostNode->right = this->cur;
                    this->cur = this->cur->left;
                }
                else {
                    res = this->cur;
                    rightMostNode->right = NULL;
                    this->cur = this->cur->right;
                    break;
                }
            }
        }
        return res;
    }
public:
    BSTIterator(TreeNode* root) {
        this->cur = root;
    }
    
    int next() {
        TreeNode* res = morrisTraversal();
        return res->val;
    }
    
    bool hasNext() {
        return this->cur != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */