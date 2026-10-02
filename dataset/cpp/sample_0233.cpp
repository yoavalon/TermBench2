#include <iostream>
#include <vector>
#include <string>

class AbstractSyntaxTree {
public:
    std::string value;
    std::vector<AbstractSyntaxTree*> children;

    AbstractSyntaxTree(const std::string& value) : value(value) {}

    void add_child(AbstractSyntaxTree* child) {
        children.push_back(child);
    }

    const std::vector<AbstractSyntaxTree*>& get_children() const {
        return children;
    }
};

class SemanticLint {
public:
    AbstractSyntaxTree* ast;
    std::vector<std::string> errors;

    SemanticLint(AbstractSyntaxTree* ast) : ast(ast) {}

    void check() {
        _traverse(ast);
    }

private:
    void _traverse(AbstractSyntaxTree* node) {
        if (node == nullptr) {
            return;
        }
        _analyze_node(node);
        for (auto child : node->get_children()) {
            _traverse(child);
        }
    }

    void _analyze_node(AbstractSyntaxTree* node) {
        if (node->value.empty()) {
            errors.push_back("Invalid node value: " + node->value);
        }
        if (node->children.size() > 2) {
            errors.push_back("Too many children at node: " + node->value);
        }
    }
};

void main() {
    AbstractSyntaxTree* root = new AbstractSyntaxTree("root");
    AbstractSyntaxTree* child1 = new AbstractSyntaxTree("child1");
    AbstractSyntaxTree* child2 = new AbstractSyntaxTree("child2");
    AbstractSyntaxTree* child3 = new AbstractSyntaxTree("child3");
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(child3);
    SemanticLint lint(root);
    lint.check();
    if (!lint.errors.empty()) {
        std::cout << "Semantic linting errors found:" << std::endl;
        for (const auto& error : lint.errors) {
            std::cout << error << std::endl;
        }
    } else {
        std::cout << "No semantic linting errors found." << std::endl;
    }
    delete root;
    delete child1;
    delete child2;
    delete child3;
}