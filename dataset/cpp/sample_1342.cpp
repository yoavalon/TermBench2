#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    int value;
    std::vector<Node> children;

    Node(int value, std::vector<Node> children = {}) : value(value), children(children) {}
};

std::vector<std::string> lint_tree(const Node& node) {
    std::vector<std::string> errors;
    if (node.children.empty() && node.value < 0) {
        errors.push_back("Negative value at node with value " + std::to_string(node.value));
    }
    for (const auto& child : node.children) {
        auto child_errors = lint_tree(child);
        errors.insert(errors.end(), child_errors.begin(), child_errors.end());
    }
    return errors;
}

int main() {
    std::vector<Node> children1 = {Node(5), Node(-3, {Node(2), Node(-1)})};
    Node tree(10, children1);
    std::vector<std::string> errors = lint_tree(tree);
    if (!errors.empty()) {
        std::cout << "Linting Errors Found:" << std::endl;
        for (const auto& error : errors) {
            std::cout << error << std::endl;
        }
    } else {
        std::cout << "No linting errors found." << std::endl;
    }
    return 0;
}