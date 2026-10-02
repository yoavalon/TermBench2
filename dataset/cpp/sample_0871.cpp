#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

bool validate(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (!node->children.empty()) {
        for (Node* child : node->children) {
            if (!validate(child)) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::string> analyze(Node* node, std::vector<std::string>* issues = nullptr) {
    if (issues == nullptr) {
        issues = new std::vector<std::string>();
    }
    if (!validate(node)) {
        issues->push_back("Invalid node structure");
        return *issues;
    }
    if (node->value == "error") {
        issues->push_back("Syntax error found");
    }
    for (Node* child : node->children) {
        analyze(child, issues);
    }
    return *issues;
}

int main() {
    Node* tree = new Node("start", {
        new Node("statement", {
            new Node("expression", {
                new Node("term", {
                    new Node("factor", {
                        new Node("number", "42")
                    })
                })
            })
        }),
        new Node("error")
    });

    std::vector<std::string> issues = analyze(tree);
    for (const std::string& issue : issues) {
        std::cout << issue << std::endl;
    }

    // Clean up dynamically allocated memory
    delete tree->children[0]->children[0]->children[0]->children[0];
    delete tree->children[0]->children[0]->children[0]->children;
    delete tree->children[0]->children[0]->children[0];
    delete tree->children[0]->children[0]->children;
    delete tree->children[0]->children[0];
    delete tree->children[0]->children;
    delete tree->children[0];
    delete tree->children[1];
    delete tree->children;
    delete tree;

    return 0;
}