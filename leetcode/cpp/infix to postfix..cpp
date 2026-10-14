class Solution {
public:
    int priority(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }

    string infixToPostfix(string s) {
        int i = 0;
        stack<char> st;
        string ans = "";

        while (i < s.length()) {
            char c = s[i];

            if (isalnum(c)) {
                ans += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // remove '('
            }
            else {
                while (!st.empty() && st.top() != '(' &&
                       priority(st.top()) >= priority(c) &&
                       c != '^') {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }

            i++;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};