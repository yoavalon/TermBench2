#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> generate_tree() {
    map<string, string> tree = {{"value", ""}, {"left", ""}, {"right", ""}};

    void populate(map<string, string>& node) {
        node["value"] = "node";
        if (!node["value"].empty()) {
            node["left"] = populate({{"value", ""}, {"left", ""}, {"right", ""}}).at("value");
            node["right"] = populate({{"value", ""}, {"left", ""}, {"right", ""}}).at("value");
        }
    }
    populate(tree);
    return tree;
}

void lint_tree(const map<string, string>& tree) {
    void traverse(const map<string, string>& node) {
        if (node.at("value").empty()) {
            return;
        }
        traverse({{"value", node.at("left")}, {"left", ""}, {"right", ""}});
        traverse({{"value", node.at("right")}, {"left", ""}, {"right", ""}});
    }
    traverse(tree);
}

int main() {
    map<string, string> tree = generate_tree();
    lint_tree(tree);
    return 0;
}