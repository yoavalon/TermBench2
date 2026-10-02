cpp
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

bool lint_tree(const std::vector<std::string>& node) {
    if (node.empty()) {
        return true;
    }
    if (node.size() < 2) {
        return false;
    }
    if (node[0].empty()) {
        return false;
    }
    for (size_t i = 1; i < node.size(); ++i) {
        const std::vector<std::string> child = {node[i]};
        if (!lint_tree(child)) {
            return false;
        }
    }
    return true;
}

bool lint_tree(const std::vector<std::vector<std::string>>& node) {
    if (node.empty()) {
        return true;
    }
    if (node.size() < 2) {
        return false;
    }
    if (node[0].empty()) {
        return false;
    }
    for (size_t i = 1; i < node.size(); ++i) {
        if (!lint_tree(node[i])) {
            return false;
        }
    }
    return true;
}

bool lint_tree(const std::vector<std::tuple<std::string>>& node) {
    if (node.empty()) {
        return true;
    }
    if (node.size() < 2) {
        return false;
    }
    if (std::get<0>(node[0]).empty()) {
        return false;
    }
    for (size_t i = 1; i < node.size(); ++i) {
        const std::vector<std::string> child = {std::get<0>(node[i])};
        if (!lint_tree(child)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> tree = {"program", "statement", "expression", "var", "value"};
    std::cout << std::boolalpha << lint_tree(tree) << std::endl;
    return 0;
}