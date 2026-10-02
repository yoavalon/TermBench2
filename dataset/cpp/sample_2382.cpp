#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class AbstractSyntaxTree {
public:
    AbstractSyntaxTree(const std::string& value, std::vector<AbstractSyntaxTree*> children = {}) 
        : value(value), children(children) {}

    void add_child(AbstractSyntaxTree* child) {
        children.push_back(child);
    }

    void traverse() {
        std::cout << value << " ";
        for (auto child : children) {
            child->traverse();
        }
    }

private:
    std::string value;
    std::vector<AbstractSyntaxTree*> children;
};

class SemanticLint {
public:
    SemanticLint(AbstractSyntaxTree* tree) : tree(tree) {}

    bool check_precision(AbstractSyntaxTree* node) {
        if (std::all_of(node->value.begin(), node->value.end(), ::isdigit)) {
            return true;
        }
        std::stringstream ss(node->value);
        double num;
        ss >> num;
        std::stringstream ss2;
        ss2 << std::fixed << std::setprecision(6) << num;
        std::string str = ss2.str();
        return str.substr(str.find('.') + 1).length() <= 6;
    }

    void lint() {
        traverse_lint(tree);
    }

private:
    AbstractSyntaxTree* tree;

    void traverse_lint(AbstractSyntaxTree* node) {
        if (!check_precision(node)) {
            std::cout << "Precision error at node with value: " << node->value << std::endl;
        }
        for (auto child : node->children) {
            traverse_lint(child);
        }
    }
};

int main() {
    AbstractSyntaxTree* tree = new AbstractSyntaxTree("root");
    tree->add_child(new AbstractSyntaxTree("3.141592653589793"));
    tree->add_child(new AbstractSyntaxTree("2.718281828459045"));
    tree->add_child(new AbstractSyntaxTree("string"));
    AbstractSyntaxTree* sub_tree = new AbstractSyntaxTree("1.4142135623730951");
    sub_tree->add_child(new AbstractSyntaxTree("0.5772156649015329"));
    tree->add_child(sub_tree);
    SemanticLint linter(tree);
    linter.lint();
    while (true) {
        // Non-terminating loop
    }
    return 0;
}