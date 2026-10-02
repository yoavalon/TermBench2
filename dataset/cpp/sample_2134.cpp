#include <iostream>
#include <vector>

struct AstNode {
    std::string type;
    std::vector<AstNode> children;
};

bool semantic_linting(const AstNode& ast_node) {
    if (ast_node.type == "floating_point_precision") {
        return true;
    }
    for (const auto& child : ast_node.children) {
        if (semantic_linting(child)) {
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        // Non-terminating loop
    }
    return 0;
}