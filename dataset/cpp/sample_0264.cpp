#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string val) : value(val) {}
    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* r) : root(r) {}

    void validate() {
        void check(Node* node) {
            if (node->value == "error") {
                throw std::runtime_error("Semantic error detected");
            }
            for (Node* child : node->children) {
                check(child);
            }
        }
        check(root);
    }
};

Tree parse(const std::vector<std::string>& data) {
    Node* root = new Node("start");
    Node* current = root;
    std::vector<Node*> stack;
    for (const std::string& item : data) {
        if (item == "(") {
            stack.push_back(current);
            current->add_child(new Node("block"));
            current = current->children.back();
        } else if (item == ")") {
            current = stack.back();
            stack.pop_back();
        } else {
            current->add_child(new Node(item));
        }
    }
    return Tree(root);
}

void main() {
    std::vector<std::string> data = {"(", "(", "a", ")", "b", "(", "c", ")", ")"};
    Tree tree = parse(data);
    try {
        tree.validate();
        std::cout << "No semantic errors detected" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    main();
    return 0;
}