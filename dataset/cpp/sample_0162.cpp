#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <tuple>

bool validate_node(const std::tuple<std::string, std::tuple<std::string, std::string, std::string>, std::tuple<std::string, std::string, std::string>>* node) {
    if (node == nullptr) {
        return true;
    }
    if (!std::holds_alternative<std::string>(std::get<0>(*node))) {
        return false;
    }
    auto* child1 = std::get<1>(*node);
    auto* child2 = std::get<2>(*node);
    if (!validate_node(child1) || !validate_node(child2)) {
        return false;
    }
    return true;
}

void analyze_tree(const std::tuple<std::string, std::tuple<std::string, std::string, std::string>, std::tuple<std::string, std::string, std::string>>* tree) {
    if (!validate_node(tree)) {
        throw std::invalid_argument("Invalid syntax tree structure");
    }
    std::vector<const std::tuple<std::string, std::tuple<std::string, std::string, std::string>, std::tuple<std::string, std::string, std::string>>*> stack;
    stack.push_back(tree);
    while (!stack.empty()) {
        auto* node = stack.back();
        stack.pop_back();
        auto* child1 = std::get<1>(*node);
        auto* child2 = std::get<2>(*node);
        if (child1 != nullptr) {
            stack.push_back(child1);
        }
        if (child2 != nullptr) {
            stack.push_back(child2);
        }
    }
}

int main() {
    auto tree = std::make_tuple("root", std::make_tuple("child1", std::make_tuple(), std::make_tuple()), std::make_tuple("child2", std::make_tuple("grandchild1", std::make_tuple(), std::make_tuple()), std::make_tuple()));
    analyze_tree(&tree);
    return 0;
}