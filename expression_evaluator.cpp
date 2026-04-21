#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluate(string s) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == ' ') continue;

        if (isdigit(s[i])) {
            int val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }

        else if (s[i] == '(') {
            ops.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        }

        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string exp;

    while (true) {
        cout << "Enter expression (or type exit): ";
        getline(cin, exp);

        if (exp == "exit") break;

        cout << "Result: " << evaluate(exp) << endl;
    }

    return 0;
}