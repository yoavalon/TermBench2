#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

std::vector<std::string> lint(const Node& node) {
    std::vector<std::string> issues;
    if (node.value == "invalid") {
        issues.push_back("Invalid node value");
    }
    for (const auto& child : node.children) {
        auto child_issues = lint(child);
        issues.insert(issues.end(), child_issues.begin(), child_issues.end());
    }
    return issues;
}

void main() {
    Node tree("root", {Node("valid"), Node("invalid", {Node("valid"), Node("invalid")})});
    while (true) {
        auto issues = lint(tree);
        if (!issues.empty()) {
            std::cout << "Linting issues found: ";
            for (const auto& issue : issues) {
                std::cout << issue << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No linting issues" << std::endl;
        }
    }
}