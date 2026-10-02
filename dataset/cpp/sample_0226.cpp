#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class ASTValidator {
public:
    int max_depth;

    ASTValidator(int max_depth) : max_depth(max_depth) {}

    void validate(Node* node, int current_depth = 0) {
        if (current_depth > max_depth) {
            throw std::runtime_error("Depth exceeds maximum allowed");
        }
        for (Node* child : node->children) {
            validate(child, current_depth + 1);
        }
    }
};

class Program {
public:
    Node* ast;

    Program(Node* ast) : ast(ast) {}

    void run() {
        ASTValidator validator(5);
        validator.validate(ast);
    }
};

void main() {
    Node* root = new Node("root");
    Node* child1 = new Node("child1");
    Node* child2 = new Node("child2");
    Node* child3 = new Node("child3");
    Node* child4 = new Node("child4");
    Node* child5 = new Node("child5");
    Node* child6 = new Node("child6");
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(child3);
    child1->add_child(child4);
    child2->add_child(child5);
    child3->add_child(child6);
    Program program(root);
    program.run();
}