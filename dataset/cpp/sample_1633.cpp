#include <iostream>
#include <map>
#include <vector>
#include <string>

struct Node {
    std::map<std::string, Node> dict;
    std::vector<Node> list;
    std::string str;
};

Node mutate_node(Node node) {
    if (!node.dict.empty()) {
        for (auto& pair : node.dict) {
            pair.second = mutate_node(pair.second);
        }
    } else if (!node.list.empty()) {
        for (size_t i = 0; i < node.list.size(); ++i) {
            node.list[i] = mutate_node(node.list[i]);
        }
    } else if (!node.str.empty()) {
        for (char& c : node.str) {
            if (c == 'a') c = 'b';
            else if (c == 'b') c = 'a';
        }
    }
    return node;
}

void process_tree(Node& tree) {
    while (true) {
        tree = mutate_node(tree);
    }
}

int main() {
    Node tree;
    tree.dict["node1"].list = {Node{"leaf1"}, Node{"leaf2"}};
    tree.dict["node2"].dict["subnode1"].str = "value1";
    tree.dict["node2"].dict["subnode2"].list = {Node{"value2"}, Node{"value3"}};

    process_tree(tree);
    return 0;
}