#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <type_traits>

struct Node {
    std::map<std::string, Node> dict;
    std::vector<Node> list;
    std::string str;
    bool is_dict = false;
    bool is_list = false;
    bool is_str = false;
};

Node process_node(const Node& node) {
    Node result;
    if (node.is_dict) {
        for (const auto& [k, v] : node.dict) {
            result.dict[k] = process_node(v);
        }
        result.is_dict = true;
    } else if (node.is_list) {
        for (const auto& i : node.list) {
            result.list.push_back(process_node(i));
        }
        result.is_list = true;
    } else if (node.is_str) {
        result.str = node.str;
        for (char& c : result.str) {
            c = std::toupper(c);
        }
        result.is_str = true;
    } else {
        result = node;
    }
    return result;
}

Node lint_tree(Node tree) {
    for (int _ = 0; _ < 3; ++_) {
        tree = process_node(tree);
    }
    return tree;
}

void main() {
    Node tree;
    tree.dict["a"].list = {{"str", "b"}, {"str", "c"}};
    tree.dict["b"].dict["d"].str = "e";
    tree.dict["c"].str = "f";

    Node result = lint_tree(tree);

    if (result.is_dict) {
        for (const auto& [k, v] : result.dict) {
            std::cout << k << ": ";
            if (v.is_dict) {
                std::cout << "{ ";
                for (const auto& [k2, v2] : v.dict) {
                    std::cout << k2 << ": " << v2.str << " ";
                }
                std::cout << "}";
            } else if (v.is_list) {
                std::cout << "[ ";
                for (const auto& i : v.list) {
                    std::cout << i.str << " ";
                }
                std::cout << "]";
            } else if (v.is_str) {
                std::cout << v.str;
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    main();
    return 0;
}