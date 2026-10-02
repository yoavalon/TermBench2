#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

std::vector<std::string> lint_tree(Node node, int depth = 0) {
    if (depth > 10) {
        throw std::runtime_error("Exceeded maximum depth");
    }
    std::vector<std::string> result = {node.value};
    for (const auto& child : node.children) {
        std::vector<std::string> child_result = lint_tree(child, depth + 1);
        result.insert(result.end(), child_result.begin(), child_result.end());
    }
    return result;
}

int main() {
    Node root("root", {Node("child1", {Node("subchild1"), Node("subchild2")}), Node("child2")});
    try {
        std::vector<std::string> result = lint_tree(root);
        for (const auto& val : result) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}