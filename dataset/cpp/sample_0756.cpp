#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

bool validate(Node node) {
    if (node.value != "+" && node.value != "-" && node.value != "*" && node.value != "/") {
        return false;
    }
    if (node.children.size() != 2) {
        return false;
    }
    return validate(node.children[0]) && validate(node.children[1]);
}

int main() {
    Node tree("+", {Node("*", {Node("2"), Node("3")}), Node("4")});
    std::cout << validate(tree) << std::endl;
    return 0;
}