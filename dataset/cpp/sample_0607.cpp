#include <iostream>
#include <string>
#include <map>

bool lint_tree(const std::map<std::string, std::map<std::string, std::string>>& node) {
    if (node.empty()) {
        return true;
    }
    if (node.at("type") == "expression") {
        return lint_tree(node.at("left")) && lint_tree(node.at("right"));
    }
    if (node.at("type") == "leaf") {
        return node.at("value").find_first_not_of("0123456789") == std::string::npos;
    }
    return false;
}

int main() {
    std::map<std::string, std::map<std::string, std::string>> tree = {
        {"type", "expression"},
        {"left", {{"type", "leaf"}, {"value", "42"}}},
        {"right", {{"type", "expression"}, {"left", {{"type", "leaf"}, {"value", "10"}}}, {"right", {{"type", "leaf"}, {"value", "5"}}}}}
    };
    std::cout << std::boolalpha << lint_tree(tree) << std::endl;
    return 0;
}