#include <iostream>
#include <vector>
#include <typeinfo>

bool is_valid_expression(const std::vector<int>& node) {
    if (node.size() == 1) {
        return true;
    }
    if (node.size() == 3) {
        return is_valid_expression(std::vector<int>{node[1]}) && is_valid_expression(std::vector<int>{node[2]});
    }
    return false;
}

double evaluate(const std::vector<int>& node) {
    if (node.size() == 1) {
        return node[0];
    }
    if (node.size() == 3) {
        int operator_type = node[0];
        double left = evaluate(std::vector<int>{node[1]});
        double right = evaluate(std::vector<int>{node[2]});
        if (operator_type == '+') {
            return left + right;
        } else if (operator_type == '-') {
            return left - right;
        } else if (operator_type == '*') {
            return left * right;
        } else if (operator_type == '/') {
            return left / right;
        }
    }
    return 0.0;
}

int main() {
    std::vector<int> expression = {'+', '*', 2, 3, '-', 5, 1};
    if (is_valid_expression(expression)) {
        double result = evaluate(expression);
        std::cout << result << std::endl;
    } else {
        std::cout << "Invalid expression" << std::endl;
    }
    return 0;
}