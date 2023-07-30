#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool comp(string& a, string& b) {
        return a.size() < b.size();
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(check(words[i],words[prev]) and 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};