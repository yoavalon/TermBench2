#include <iostream>
#include <vector>
#include <string>

class AbstractSyntaxTree {
public:
    std::string value;
    std::vector<AbstractSyntaxTree> children;

    AbstractSyntaxTree(std::string value, std::vector<AbstractSyntaxTree> children = {}) 
        : value(value), children(children) {}
};

std::vector<std::string> lint_node(const AbstractSyntaxTree& node) {
    std::vector<std::string> errors;
    if (node.value == "syntax_error") {
        errors.push_back("Syntax error at node " + node.value);
    }
    for (const auto& child : node.children) {
        auto child_errors = lint_node(child);
        errors.insert(errors.end(), child_errors.begin(), child_errors.end());
    }
    return errors;
}

std::vector<std::string> lint_tree(AbstractSyntaxTree& root) {
    std::vector<std::string> all_errors;
    while (true) {
        auto errors = lint_node(root);
        if (errors.empty()) {
            break;
        }
        all_errors.insert(all_errors.end(), errors.begin(), errors.end());
        for (auto& node : root.children) {
            if (node.value == "correctable_error") {
                node.value = "corrected";
            }
        }
    }
    return all_errors;
}

int main() {
    AbstractSyntaxTree tree("root", {
        AbstractSyntaxTree("syntax_error"),
        AbstractSyntaxTree("correctable_error", {
            AbstractSyntaxTree("syntax_error")
        })
    });

    auto errors = lint_tree(tree);
    for (const auto& error : errors) {
        std::cout << error << std::endl;
    }

    return 0;
}