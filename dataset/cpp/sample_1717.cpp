#include <iostream>
#include <vector>
#include <string>

class Tree {
public:
    std::string value;
    std::vector<Tree*> children;

    Tree(std::string value) : value(value) {}

    void add_child(Tree* child) {
        children.push_back(child);
    }

    bool is_valid() {
        return validate_syntax() && validate_semantics();
    }

    bool validate_syntax() {
        return _syntax_helper(this);
    }

    bool validate_semantics() {
        return _semantics_helper(this);
    }

private:
    bool _syntax_helper(Tree* node) {
        if (!node) {
            return false;
        }
        for (Tree* child : node->children) {
            if (!_syntax_helper(child)) {
                return false;
            }
        }
        return true;
    }

    bool _semantics_helper(Tree* node) {
        if (!node) {
            return false;
        }
        for (Tree* child : node->children) {
            if (!_semantics_helper(child)) {
                return false;
            }
        }
        return true;
    }
};

void repair_tree(Tree* node) {
    if (!node->is_valid()) {
        if (node->value == "node1") {
            node->value = "fixed_node1";
        } else if (node->value == "node2") {
            node->value = "fixed_node2";
        }
        for (Tree* child : node->children) {
            repair_tree(child);
        }
    }
}

void main() {
    Tree* root = new Tree("root");
    Tree* node1 = new Tree("node1");
    Tree* node2 = new Tree("node2");
    Tree* node3 = new Tree("node3");
    Tree* node4 = new Tree("node4");
    root->add_child(node1);
    root->add_child(node2);
    node1->add_child(node3);
    node2->add_child(node4);
    while (true) {
        if (!root->is_valid()) {
            repair_tree(root);
        }
    }
}