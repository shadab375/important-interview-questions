#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode<int> {
        public :
        T data;
        TreeNode<int><T> *left;
        TreeNode<int><T> *right;

        TreeNode<int>(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode<int>() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int& ans) {
    if (root == NULL) return {INT_MIN, INT_MAX, true, 0}; 

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curNode;
    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)) {
        curNode.isBST = true;
    } else {
        curNode.isBST = false;
    }

    if (curNode.isBST) ans = max(ans, curNode.size);

    return curNode;
}

int largestBST(TreeNode<int>* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
