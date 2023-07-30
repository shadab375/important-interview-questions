class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> s;
        for (int i=0; i<exp.size(); i++) {
            if (exp[i] == ')') {
                int t = 0, f = 0;
                while (s.top() == 't' || s.top() == 'f') {
                    if (s.top() == 't') t = 1;
                    else f = 1;
                    s.pop();
                }

                char op = s.top();
                s.pop();

                if (op == '!') {
                    if (t) s.push('f');
                    else s.push('t');
                }
                else if (op == '|') {
                    if (t) s.push('t');
                    else s.push('f');
                }
                else if (op == '&') {
                    if (f) s.push('f');
                    else s.push('t');
                }
            }
            else if (exp[i] != ',' && exp[i] != '(') {
                s.push(exp[i]);
            }
        }
        if (s.top() == 't') return true;
        else return false;
    }
};