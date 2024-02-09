//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* construct(int arr[], int& i, int lb) {
    if (i == -1 || arr[i] < lb) return NULL;
    
    Node* root = new Node(arr[i--]);
    root->right = construct(arr, i, root->data);
    root->left = construct(arr, i, lb);
    
    return root;
}

Node *constructTree (int post[], int size) {
    int i = size-1;
    return construct(post, i, -(int)1e8);
}