class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for (int i=0; i<s.length(); i++) {
            if (s[i] == '*') result.pop_back();
            else result.push_back(s[i]);
        }

        return result;
    }
};