#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <type_traits>

struct Node {
    std::map<std::string, Node> dict;
    std::vector<Node> list;
    double value;
    bool is_dict;
    bool is_list;
    bool is_value;

    Node() : is_dict(false), is_list(false), is_value(false) {}

    Node(double v) : value(v), is_dict(false), is_list(false), is_value(true) {}

    Node(const std::map<std::string, Node>& d) : dict(d), is_dict(true), is_list(false), is_value(false) {}

    Node(const std::vector<Node>& l) : list(l), is_dict(false), is_list(true), is_value(false) {}
};

Node process_node(const Node& node, int precision) {
    if (node.is_value) {
        return Node(round(node.value * pow(10, precision)) / pow(10, precision));
    } else if (node.is_list) {
        std::vector<Node> result;
        for (const auto& child : node.list) {
            result.push_back(process_node(child, precision));
        }
        return Node(result);
    } else if (node.is_dict) {
        std::map<std::string, Node> result;
        for (const auto& [key, value] : node.dict) {
            result[key] = process_node(value, precision);
        }
        return Node(result);
    }
    return node;
}

void lint_tree(Node& tree, int precision) {
    while (true) {
        tree = process_node(tree, precision);
    }
}

int main() {
    Node tree;
    tree.dict["a"] = Node(1.23456789);
    tree.dict["b"] = Node({Node(2.3456789), Node(3.45678901)});
    tree.dict["c"] = Node();
    tree.dict["c"].dict["d"] = Node(4.56789012);
    tree.dict["c"].dict["e"] = Node({Node(5.67890123), Node(6.78901234)});

    lint_tree(tree, 4);

    return 0;
}