#include <bits/stdc++.h>
using namespace std;

vector<int> permute(vector<vector<int>> &arr, int n) {
    vector<int> ans;
    vector<pair<int, int>> order; // total_time, order_id
    
    for (int i=0; i<n; i++) {
        int total_time = arr[i][0] + arr[i][1];
        order.push_back({total_time, i+1});
    }
    
    sort(order.begin(), order.end());
    
    for (int i=0; i<n; i++) {
        ans.push_back(order[i].second);
    }
    
    return ans;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vector<vector<int>> arr(n);

		for (int i=0; i<n; i++) {
			int a, b;
			cin>>a>>b;
			arr[i].push_back(a);
			arr[i].push_back(b);
		}

		vector<int> ans;
		ans = permute(arr, n);
		for (int i=0; i<n; i++) {
			cout<<ans[i]<<"\n";
		}
	}

	return 0;
}