// METHOD - 1
class Solution {
public:
    vector<vector<int>> result;

    void solve(int start, int k, int n, vector<int>& temp) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        if (start > n) return;

        temp.push_back(start);
        solve(start+1, k-1, n, temp);
        temp.pop_back();
        solve(start+1, k, n, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, k, n, temp);
        return result;
    }
};

// METHOD - 2
class Solution {
public:
    vector<vector<int>> result;

    void solve(int start, int k, int n, vector<int>& temp) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        
        for (int i=start; i<=n; i++) {
            temp.push_back(i);
            solve(i+1, k-1, n, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, k, n, temp);
        return result;
    }
};