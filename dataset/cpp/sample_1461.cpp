#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(const std::string& value, const std::vector<Node*>& children = {}) : value(value), children(children) {}
};

class AbstractSyntaxTree {
public:
    Node* root;

    AbstractSyntaxTree(Node* root) : root(root) {}

    std::vector<std::string> traverse() {
        std::vector<std::string> result;
        _traverse(root, result);
        return result;
    }

private:
    void _traverse(Node* node, std::vector<std::string>& result) {
        if (node) {
            result.push_back(node->value);
            for (Node* child : node->children) {
                _traverse(child, result);
            }
        }
    }
};

class SemanticLint {
public:
    AbstractSyntaxTree* ast;

    SemanticLint(AbstractSyntaxTree* ast) : ast(ast) {}

    std::vector<std::string> analyze() {
        std::vector<std::string> issues;
        for (const std::string& node : ast->traverse()) {
            if (_has_issue(node)) {
                issues.push_back(node);
            }
        }
        return issues;
    }

private:
    bool _has_issue(const std::string& node) {
        return node == "invalid";
    }
};

void main() {
    Node* root = new Node("root", {new Node("valid"), new Node("invalid", {new Node("valid"), new Node("invalid")})});
    AbstractSyntaxTree* ast = new AbstractSyntaxTree(root);
    SemanticLint* linter = new SemanticLint(ast);
    std::vector<std::string> issues = linter->analyze();
    std::cout << "Issues found: ";
    for (const std::string& issue : issues) {
        std::cout << issue << " ";
    }
    std::cout << std::endl;
}