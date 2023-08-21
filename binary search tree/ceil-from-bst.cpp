#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int key){
    int ceil = -1;
    BinaryTreeNode<int>* cur = root;

    while (cur) {
        if (cur->data == key) {
            ceil = cur->data;
            return ceil;
        }
        if (key > cur->data) {
            cur = cur->right;
        }
        else {
            ceil = cur->data;
            cur = cur->left;
        }
    }

    return ceil;
}