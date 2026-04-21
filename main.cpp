#include <iostream>
#include <stack>
#include <stdexcept>
#include <cctype>
using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to apply operation
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;

    if (op == '/') {
        if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    }

    throw runtime_error("Unknown operator");
}

// Validate expression
bool isValidExpression(string s) {
    int balance = 0;

    for (char c : s) {
        if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == ' ')
            continue;
        else
            return false;

        if (c == '(') balance++;
        if (c == ')') balance--;

        if (balance < 0) return false;
    }

    return balance == 0;
}

// Evaluate expression
int evaluate(string s) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == ' ') continue;

        // If number
        if (isdigit(s[i])) {
            int val = 0;

            while (i < s.length() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }

        // Opening bracket
        else if (s[i] == '(') {
            ops.push(s[i]);
        }

        // Closing bracket
        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if (!ops.empty()) ops.pop();
        }

        // Operator
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

    // Final evaluation
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

// Main function
int main() {
    string exp;

    while (true) {
        cout << "\nEnter expression (or type 'exit'): ";
        getline(cin, exp);

        if (exp == "exit") break;

        if (!isValidExpression(exp)) {
            cout << "Invalid expression! Please enter a valid one.\n";
            continue;
        }

        try {
            int result = evaluate(exp);
            cout << "Result: " << result << endl;
        } 
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
