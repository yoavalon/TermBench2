#include <iostream>
#include <vector>
#include <stdexcept>

bool is_valid_ast(const std::vector<double>& node) {
    if (node.size() == 1 && (node[0] == static_cast<int>(node[0]) || node[0] == static_cast<float>(node[0]))) {
        return true;
    } else if (node.size() == 3) {
        return is_valid_ast({node[0]}) && is_valid_ast({node[2]});
    }
    return false;
}

double evaluate_ast(const std::vector<double>& node) {
    if (node.size() == 1 && (node[0] == static_cast<int>(node[0]) || node[0] == static_cast<float>(node[0]))) {
        return node[0];
    } else if (node.size() == 3) {
        double left = evaluate_ast({node[0]});
        char operator_ = static_cast<char>(node[1]);
        double right = evaluate_ast({node[2]});
        if (operator_ == '+') {
            return left + right;
        } else if (operator_ == '-') {
            return left - right;
        } else if (operator_ == '*') {
            return left * right;
        } else if (operator_ == '/') {
            return left / right;
        }
    }
    throw std::invalid_argument("Invalid AST node");
}

int main() {
    std::vector<double> ast = {3, '+', 2, '*', 5, '+', 1};
    if (is_valid_ast(ast)) {
        double result = evaluate_ast(ast);
        std::cout << result << std::endl;
    } else {
        std::cout << "Invalid AST" << std::endl;
    }
    return 0;
}