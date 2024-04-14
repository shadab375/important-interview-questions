//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string encryptString(string s) {
        int count = 1;
        string ans = "";
        char ch = s[0];
        
        for (int i=1; i<s.length(); i++) {
            if (s[i] == s[i-1]) count++;
            else {
                ans += ch;
                string hx = "";
                while (count != 0) {
                    int rem = count % 16;
                    hx += rem < 10 ? '0' + rem : ('a' - 10) + rem;
                    count /= 16;
                }
                ans += hx;
                ch = s[i];
                count = 1;
            }
        }
        
        ans += ch;
        string hx = "";
        while (count != 0) {
            int rem = count % 16;
            hx += rem < 10 ? '0' + rem : ('a' - 10) + rem;
            count /= 16;
        }
        ans += hx;
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends