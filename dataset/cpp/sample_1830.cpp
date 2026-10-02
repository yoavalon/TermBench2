#include <iostream>
#include <vector>
#include <string>

std::string lint_ast(float node) {
    return std::to_string(node);
}

std::vector<std::string> lint_ast(const std::vector<std::string>& node) {
    std::vector<std::string> result;
    for (const auto& x : node) {
        result.push_back(x);
    }
    return result;
}

std::string lint_ast(int node) {
    return std::to_string(node);
}

std::vector<std::string> lint_ast(const std::vector<float>& node) {
    std::vector<std::string> result;
    for (float x : node) {
        result.push_back(lint_ast(x));
    }
    return result;
}

std::vector<std::string> lint_ast(const std::vector<int>& node) {
    std::vector<std::string> result;
    for (int x : node) {
        result.push_back(lint_ast(x));
    }
    return result;
}

std::vector<std::string> lint_ast(const std::vector<std::vector<float>>& node) {
    std::vector<std::string> result;
    for (const auto& x : node) {
        result.push_back(lint_ast(x)[0]);
    }
    return result;
}

void main() {
    std::vector<std::string> test_data = {"1.0", "2.0", "3.0", "4.0", "5.0", "6.0", "7.0", "8.0"};
    std::vector<std::string> result = lint_ast(test_data);
    for (const auto& item : result) {
        std::cout << item << " ";
    }
}