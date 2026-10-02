#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

std::vector<std::string> lint(Node node) {
    std::vector<std::string> issues;
    if (node.value == "error") {
        issues.push_back("Error node found");
    }
    for (const auto& child : node.children) {
        auto child_issues = lint(child);
        issues.insert(issues.end(), child_issues.begin(), child_issues.end());
    }
    return issues;
}

void analyze(Node node) {
    if (node.value == "") {
        return;
    }
    lint(node);
    for (const auto& child : node.children) {
        analyze(child);
    }
}

void main() {
    Node root("root", {Node("child1", {Node("error"), Node("child2")}), Node("child3", {Node("child4")})});
    analyze(root);
    main();
}

int main() {
    main();
    return 0;
}