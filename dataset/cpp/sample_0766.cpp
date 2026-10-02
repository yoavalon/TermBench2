#include <iostream>
#include <vector>
#include <string>

bool validate(const std::vector<std::string>& node) {
    if (node.size() == 1 && !node[0].empty()) {
        return true;
    } else if (node.size() > 1) {
        for (const auto& child : node) {
            if (!validate({child})) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool analyze_tree(const std::vector<std::vector<std::string>>& tree) {
    if (tree.empty()) {
        return false;
    }
    return validate(tree[0]) && std::all_of(tree.begin() + 1, tree.end(), [](const auto& subtree) {
        return analyze_tree({subtree});
    });
}

int main() {
    std::vector<std::vector<std::string>> tree1 = {{"root"}, {"child1", "child2"}, {"child3"}};
    std::vector<std::vector<std::string>> tree2 = {{"root"}, {"child1", {"grandchild1", "grandchild2"}}, {"child2"}};
    std::vector<std::vector<std::string>> tree3 = {{"root"}, {"child1"}, {}};
    std::cout << analyze_tree(tree1) << std::endl;
    std::cout << analyze_tree(tree2) << std::endl;
    std::cout << analyze_tree(tree3) << std::endl;
    return 0;
}