#include <iostream>
#include <vector>
#include <iomanip>

class Node {
public:
    double value;
    std::vector<Node> children;

    Node(double value, std::vector<Node> children = {}) : value(value), children(children) {}
};

double evaluate(Node& node) {
    if (node.value == static_cast<int>(node.value)) {
        return static_cast<int>(node.value);
    }
    return static_cast<double>(std::round(node.value * 100000)) / 100000;
}

void process_tree(Node& root) {
    if (!root.children.empty()) {
        root.value = evaluate(root);
        for (auto& child : root.children) {
            process_tree(child);
        }
    }
}

int main() {
    Node tree(3.1415926535, {Node(2.7182818284), Node(1.4142135623)});
    process_tree(tree);
    std::cout << std::fixed << std::setprecision(5) << tree.value << " " << tree.children[0].value << " " << tree.children[1].value << std::endl;
    return 0;
}