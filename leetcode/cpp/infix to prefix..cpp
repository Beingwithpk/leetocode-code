#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getPrecedence(char c) {
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    string infixToPostfix(string infix) {
        stack<char> st;
        string output = "";

        for (char c : infix) {
            if (isalnum(c)) {
                output += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    output += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else if (isOperator(c)) {
                while (!st.empty() && st.top() != '(' &&
                       getPrecedence(st.top()) >= getPrecedence(c)) {
                    output += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            output += st.top();
            st.pop();
        }

        return output;
    }

    string infixToPrefix(string infix) {
        reverse(infix.begin(), infix.end());

        for (char &c : infix) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        string postfix = infixToPostfix(infix);

        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};