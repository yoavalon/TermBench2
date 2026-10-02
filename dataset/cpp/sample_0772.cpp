#include <iostream>
#include <vector>
#include <unordered_set>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

bool validate(Node* node, std::unordered_set<std::string>& rules) {
    if (!node) {
        return true;
    }
    if (rules.find(node->value) == rules.end()) {
        return false;
    }
    for (Node* child : node->children) {
        if (!validate(child, rules)) {
            return false;
        }
    }
    return true;
}

int main() {
    Node* tree = new Node("root", {
        new Node("a", {new Node("b"), new Node("c")}),
        new Node("d", {new Node("e")})
    });
    std::unordered_set<std::string> rules = {"root", "a", "b", "c", "d", "e"};
    std::cout << validate(tree, rules) << std::endl;
    return 0;
}