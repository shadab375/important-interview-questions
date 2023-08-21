/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }
    };

*************************************************************/

void inorder(TreeNode<int>* root, vector<int>&in) {
    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size()+b.size());
    
    int i=0, j=0, k=0;
    while (i<a.size() && j<b.size()) {
        if (a[i]<b[j]) ans[k++] = a[i++];
        else ans[k++] = b[j++];
    }
    while (i<a.size()) ans[k++] = a[i++];
    while (j<b.size()) ans[k++] = b[j++];

    return ans;
}

vector<int> mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);
    return mergeArrays(in1, in2);
}