#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

struct Node {
    std::string type;
    std::vector<Node> children;
};

bool validate_node(const Node& node) {
    if (node.type.empty()) {
        return false;
    }
    for (const auto& child : node.children) {
        if (!validate_node(child)) {
            return false;
        }
    }
    return true;
}

bool analyze_tree(const Node& tree) {
    if (!validate_node(tree)) {
        throw std::invalid_argument("Invalid syntax tree structure");
    }
    for (const auto& child : tree.children) {
        if (!analyze_tree(child)) {
            return false;
        }
    }
    return true;
}

int main() {
    Node tree = {"root", {{"branch", {}}, {"branch", {{"leaf", {}}}}}};
    bool result = analyze_tree(tree);
    std::cout << "Syntax tree is valid: " << result << std::endl;
    return 0;
}