#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value) : value(value) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    bool validate() {
        if (!root) {
            return false;
        }
        std::stack<Node*> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node* node = stack.top();
            stack.pop();
            if (node->value == "invalid") {
                return false;
            }
            for (Node* child : node->children) {
                stack.push(child);
            }
        }
        return true;
    }
};

bool check_tree(Tree* tree) {
    if (!tree) {
        return false;
    }
    if (!tree->validate()) {
        return false;
    }
    return true;
}

void main() {
    Node* root = new Node("valid");
    Node* child1 = new Node("valid");
    Node* child2 = new Node("invalid");
    root->add_child(child1);
    root->add_child(child2);
    Tree* tree = new Tree(root);
    bool result = check_tree(tree);
    std::cout << result << std::endl;
    delete root;
    delete child1;
    delete child2;
    delete tree;
}

int main() {
    main();
    return 0;
}