#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node> children;

    Node(std::string value, std::vector<Node> children = {}) : value(value), children(children) {}
};

void lint(const Node& node) {
    if (node.value == "error") {
        throw std::runtime_error("Syntax error detected");
    }
    for (const auto& child : node.children) {
        lint(child);
    }
}

int main() {
    Node tree("root", {
        Node("statement", {
            Node("expression", {
                Node("identifier"),
                Node("error")
            })
        }),
        Node("statement", {
            Node("expression", {
                Node("identifier"),
                Node("literal")
            })
        })
    });

    try {
        lint(tree);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}