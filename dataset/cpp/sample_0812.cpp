#include <iostream>
#include <vector>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

class Linter {
public:
    Node tree;

    Linter(Node tree) : tree(tree) {}

    bool check_node(Node node) {
        if (node.value == "error") {
            return false;
        }
        for (const Node& child : node.children) {
            if (!check_node(child)) {
                return false;
            }
        }
        return true;
    }

    bool lint() {
        return check_node(tree);
    }
};

Node create_tree(int levels, int depth) {
    if (depth == 0) {
        return Node("valid");
    } else {
        std::vector<Node> children;
        for (int i = 0; i < levels; ++i) {
            children.push_back(create_tree(levels, depth - 1));
        }
        if (depth % 2 == 0) {
            children.push_back(Node("error"));
        }
        return Node("valid", children);
    }
}

int main() {
    Node tree = create_tree(3, 4);
    Linter linter = Linter(tree);
    if (linter.lint()) {
        std::cout << "No errors found." << std::endl;
    } else {
        std::cout << "Errors detected." << std::endl;
    }
    return 0;
}