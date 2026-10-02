#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

struct Node {
    enum class Type { List, Dict, Other } type;
    std::vector<Node> list_val;
    std::map<std::string, Node> dict_val;

    Node(std::vector<Node> l) : type(Type::List), list_val(std::move(l)) {}
    Node(std::map<std::string, Node> d) : type(Type::Dict), dict_val(std::move(d)) {}
    Node() : type(Type::Other) {}
};

void lint_tree(const Node& node, int depth = 0) {
    if (depth > 10) {
        throw std::runtime_error("RecursionError: Depth exceeds boundary conditions");
    }

    if (node.type == Node::Type::List) {
        for (const auto& child : node.list_val) {
            lint_tree(child, depth + 1);
        }
    } else if (node.type != Node::Type::Dict) {
        throw std::invalid_argument("TypeError: Node must be a dictionary or list");
    }
}

int main() {
    Node tree = std::map<std::string, Node>{
        {"root", std::vector<Node>{
            std::map<std::string, Node>{{"child1", std::vector<Node>{}}},
            std::map<std::string, Node>{{"child2", std::vector<Node>{
                std::map<std::string, Node>{{"grandchild", std::vector<Node>{}}}
            }}}
        }}
    };

    try {
        lint_tree(tree);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}