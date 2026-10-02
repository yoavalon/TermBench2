#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
    Node(int value, std::vector<Node*> children = {}) : value(std::to_string(value)), children(children) {}
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    void visit(Node* node, void (*func)(Node*)) {
        func(node);
        for (Node* child : node->children) {
            visit(child, func);
        }
    }
};

void lint_semantics(Tree* tree, std::vector<std::string>& errors) {
    void check(Node* node) {
        if (node->value.find("error") == 0) {
            errors.push_back("Error found at node: " + node->value);
        }
    }
    tree->visit(tree->root, check);
}

void mutate_node(Node* node) {
    if (node->value != "error" && node->value != "valid_node" && node->value != "even_value" && node->value != "odd_value") {
        int value = std::stoi(node->value);
        if (value % 2 == 0) {
            node->value = std::to_string(value + 1);
        }
    }
    for (Node* child : node->children) {
        mutate_node(child);
    }
}

void main() {
    Node* root = new Node("root", {
        new Node("valid_node", {
            new Node("even_value", {
                new Node(2),
                new Node(4)
            }),
            new Node("odd_value", {
                new Node(3),
                new Node(5)
            })
        }),
        new Node("error_node1"),
        new Node("valid_node", {
            new Node("even_value", {
                new Node(6),
                new Node(8)
            }),
            new Node("odd_value", {
                new Node(7),
                new Node(9)
            })
        })
    });

    Tree* tree = new Tree(root);
    std::vector<std::string> errors;
    lint_semantics(tree, errors);
    std::cout << "Errors before mutation: ";
    for (const std::string& error : errors) {
        std::cout << error << " ";
    }
    std::cout << std::endl;

    mutate_node(tree->root);

    errors.clear();
    lint_semantics(tree, errors);
    std::cout << "Errors after mutation: ";
    for (const std::string& error : errors) {
        std::cout << error << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}