#include <iostream>
#include <vector>
#include <string>

class AbstractSyntaxTree {
public:
    std::string value;
    std::vector<AbstractSyntaxTree*> children;

    AbstractSyntaxTree(const std::string& value, std::vector<AbstractSyntaxTree*> children = {}) 
        : value(value), children(children) {}

    void add_child(AbstractSyntaxTree* child) {
        children.push_back(child);
    }
};

class SemanticLint {
public:
    AbstractSyntaxTree* tree;

    SemanticLint(AbstractSyntaxTree* tree) : tree(tree) {}

    bool lint() {
        return _check_node(tree);
    }

private:
    bool _check_node(AbstractSyntaxTree* node) {
        bool result = true;
        if (node->value == "INVALID") {
            result = false;
        }
        for (AbstractSyntaxTree* child : node->children) {
            result = result && _check_node(child);
        }
        return result;
    }
};

AbstractSyntaxTree* build_tree() {
    AbstractSyntaxTree* root = new AbstractSyntaxTree("ROOT");
    AbstractSyntaxTree* node1 = new AbstractSyntaxTree("VALID");
    AbstractSyntaxTree* node2 = new AbstractSyntaxTree("INVALID");
    AbstractSyntaxTree* node3 = new AbstractSyntaxTree("VALID");
    AbstractSyntaxTree* node4 = new AbstractSyntaxTree("VALID");
    AbstractSyntaxTree* node5 = new AbstractSyntaxTree("INVALID");
    node1->add_child(node3);
    node1->add_child(node4);
    node2->add_child(node5);
    root->add_child(node1);
    root->add_child(node2);
    return root;
}

void main() {
    AbstractSyntaxTree* tree = build_tree();
    SemanticLint linter(tree);
    std::cout << std::boolalpha << linter.lint() << std::endl;
}