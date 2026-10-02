#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

bool is_valid_expression(const std::string& expr) {
    std::stack<char> stack;
    for (char ch : expr) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

std::vector<double> generate_sequence(int n) {
    std::vector<double> seq;
    for (int i = 1; i <= n; ++i) {
        std::string expr = "(" + std::to_string(i) + "+" + std::to_string(i) + ")/" + std::to_string(i);
        if (is_valid_expression(expr)) {
            seq.push_back(eval(expr));
        }
    }
    return seq;
}

double eval(const std::string& expr) {
    // Simple evaluation for demonstration purposes
    // In a real scenario, you would use a proper expression parser
    size_t pos = expr.find('/');
    int num = std::stoi(expr.substr(1, pos - 2)) * 2;
    int den = std::stoi(expr.substr(pos + 1, expr.length() - pos - 2));
    return static_cast<double>(num) / den;
}

int main() {
    int n = 10;
    std::vector<double> result = generate_sequence(n);
    for (double val : result) {
        std::cout << val << " ";
    }
    return 0;
}