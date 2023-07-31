#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  struct Node *left, *right;
};

void allTraversal(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
  if (root == NULL) return;
  stack<pair<Node*, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    auto& it = st.top();
    
    if (it.second == 1) {
      pre.push_back(it.first->val);
      it.second++;
      if (it.first->left) st.push({it.first->left, 1});
    }
    else if (it.second == 2) {
      in.push_back(it.first->val);
      it.second++;
      if (it.first->right) st.push({it.first->right, 1});
    }
    else {
      post.push_back(it.first->val);
      st.pop();
    }
  }
}


struct Node *newNode(int val)
{
  struct Node *Node = (struct Node *)malloc(sizeof(struct Node));
  Node->val = val;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}

int main()
{

  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  vector<int> pre, in, post;
  allTraversal(root, pre, in, post);

  cout << "The preorder Traversal is : ";
  for (auto nodeVal : pre)
  {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal : in)
  {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal : post)
  {
    cout << nodeVal << " ";
  }
  cout << endl;

  return 0;
}