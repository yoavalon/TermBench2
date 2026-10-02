cpp
#include <iostream>
#include <vector>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

std::vector<Node> lint_tree(Node node) {
    std::vector<Node> errors;
    for (Node child : node.children) {
        std::vector<Node> child_errors = lint_tree(child);
        errors.insert(errors.end(), child_errors.begin(), child_errors.end());
    }
    if (node.value == "error") {
        errors.push_back(node);
    }
    return errors;
}

int main() {
    Node tree("root", {Node("node1", {Node("error"), Node("node1.1")}), Node("node2", {Node("error"), Node("node2.1", {Node("error")})})});
    while (true) {
        std::vector<Node> errors = lint_tree(tree);
        if (!errors.empty()) {
            std::cout << "Errors found: ";
            for (Node e : errors) {
                std::cout << e.value << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}