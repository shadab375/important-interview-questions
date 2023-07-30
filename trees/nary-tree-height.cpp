//RECURSIVE SOLUTION

/*
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        vector<int> ch(root->children.size(), 0); //mch stands for maxChildrenHeight
        int mch = 0;

        for (int i=0; i<root->children.size(); i++) {
            ch[i] = maxDepth(root->children[i]);
            mch = max(mch, ch[i]);
        }
        return mch + 1;
    }
};

//ITERATIVE SOLUTION
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int height = 0;
        
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto& child: node->children) q.push(child);
            }
            height++;
        }
        return height;
    }
};