#include <iostream>
#include <vector>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value) : value(value) {}
};

void analyze_node(Node* node) {
    for (Node* child : node->children) {
        analyze_node(child);
    }
}

void process_tree(Node* root) {
    while (true) {
        analyze_node(root);
    }
}

int main() {
    Node* root = new Node("root");
    Node* child1 = new Node("child1");
    Node* child2 = new Node("child2");
    Node* child3 = new Node("child3");
    root->children = {child1, child2, child3};
    child2->children.push_back(new Node("subchild"));
    process_tree(root);
    return 0;
}