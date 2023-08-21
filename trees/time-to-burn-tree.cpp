#include <bits/stdc++.h>

BinaryTreeNode<int>* markParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent, int start) {
    if (root == NULL) return NULL;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* target = NULL;

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if (node->data == start) {
            target = node;
            break;
        }
        
        if (node->left) {
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right) {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
    
    return target;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    if (root == NULL) return 0;
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    BinaryTreeNode<int>* target = markParents(root, parent, start);
    unordered_map<BinaryTreeNode<int>*, bool> vis;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    vis[target] = true;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if (node->left && !vis[node->left]) {
                q.push(node->left);
                vis[node->left] = true;
                flag = true;
            }
            if (node->right && !vis[node->right]) {
                q.push(node->right);
                vis[node->right] = true;
                flag = true;
            }
            if (parent[node] && !vis[parent[node]]) {
                q.push(parent[node]);
                vis[parent[node]] = true;
                flag = true;
            }
        }
        if (flag == true) time++;
    }
    return time;
}
