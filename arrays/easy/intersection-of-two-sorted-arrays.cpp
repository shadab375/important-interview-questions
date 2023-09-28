#include <bits/stdc++.h> 
using namespace std;

vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
	vector<int> ans;
	int i = 0, j = 0;

	while (i<a.size() && j<b.size()) {
		if (a[i] < b[j]) i++;
		else if (a[i] > b[j]) j++;
		else {
			ans.push_back(a[i]);
			i++;
			j++;
		}
	}

	return ans;
}