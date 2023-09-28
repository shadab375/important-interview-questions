//method-1 (normal stack)

class Solution {
public:
    int operate(int& a, int& b, string& s) {
        if (s == "+") return a + b;
        if (s == "-") return a - b;
        if (s == "*") return a * b;
        if (s == "/") return a / b;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res = 0;

        for (auto &s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                res = operate(a, b, s);
                st.push(res);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};

//method-2 (fancy map)
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res = 0;

        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int a, int b) { return a+b; }},
            {"-", [](int a, int b) { return a-b; }},
            {"*", [](int a, int b) { return a*b; }},
            {"/", [](int a, int b) { return a/b; }},
        };

        for (auto &s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                res = mp[s](a, b);
                st.push(res);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
