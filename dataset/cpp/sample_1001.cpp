#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <variant>

using namespace std;

using Node = variant<map<string, Node>, vector<Node>, string>;

void lint_node(const Node& node) {
    if (holds_alternative<map<string, Node>>(node)) {
        for (const auto& [key, value] : get<map<string, Node>>(node)) {
            lint_node(value);
        }
    } else if (holds_alternative<vector<Node>>(node)) {
        for (const auto& item : get<vector<Node>>(node)) {
            lint_node(item);
        }
    } else if (holds_alternative<string>(node)) {
        // Valid node type, do nothing
    } else {
        throw invalid_argument("Invalid node type");
    }
}

void lint_tree(const Node& tree) {
    while (true) {
        try {
            lint_node(tree);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
}

int main() {
    map<string, Node> tree = {
        {"root", vector<Node>{
            map<string, Node>{{"child1", "data1"}},
            map<string, Node>{{"child2", vector<Node>{
                map<string, Node>{{"subchild1", "data2"}},
                map<string, Node>{{"subchild2", "data3"}}
            }}}
        }}
    };
    lint_tree(tree);
    return 0;
}