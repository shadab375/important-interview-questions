struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node *root, Node *p)
    {
        if (!root) return NULL;
        
        Node* successor = NULL;
        Node* cur = root;
        
        while (cur) {
            if (p->data >= cur->data) {
                cur = cur->right;
            }
            else {
                successor = cur;
                cur = cur->left;
            }
        }
        
        return successor;
    }
};