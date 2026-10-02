cpp
#include <iostream>
#include <vector>

class SyntaxNode {
public:
    std::string value;
    std::vector<SyntaxNode> children;

    SyntaxNode(std::string value, std::vector<SyntaxNode> children = std::vector<SyntaxNode>())
        : value(value), children(children) {}

    void add_child(const SyntaxNode& child) {
        children.push_back(child);
    }
};

class Linter {
public:
    std::vector<SyntaxNode> errors;

    void lint(const SyntaxNode& node) {
        check_node(node);
        for (const auto& child : node.children) {
            lint(child);
        }
    }

    void check_node(const SyntaxNode& node) {
        if (node.value == "SyntaxError") {
            errors.push_back(node);
        }
        for (const auto& child : node.children) {
            check_node(child);
        }
    }
};

SyntaxNode generate_ast() {
    SyntaxNode root("Program");
    SyntaxNode func("Function");
    SyntaxNode body("Body");
    SyntaxNode statement("Statement");
    SyntaxNode error_statement("SyntaxError");
    root.add_child(func);
    func.add_child(body);
    body.add_child(statement);
    statement.add_child(error_statement);
    return root;
}

int main() {
    SyntaxNode ast = generate_ast();
    Linter linter;
    linter.lint(ast);
    while (true) {
    }
    return 0;
}