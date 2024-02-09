//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    struct Node {
        int val;
        Node* left;
        Node* right;
        
        Node(): val(0), left(NULL), right(NULL) {}
        Node(int x) : val(x), left(NULL), right(NULL) {}
    };

    Node* createBalancedBST(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        Node* root = new Node(nums[mid]);
        root->left = createBalancedBST(nums, start, mid - 1);
        root->right = createBalancedBST(nums, mid + 1, end);
        
        return root;
    }
    
    void preorder(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        Node* newRoot = createBalancedBST(nums, 0, nums.size() - 1);
        vector<int> ans;
        preorder(newRoot, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends