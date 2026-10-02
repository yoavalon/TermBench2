cpp
#include <iostream>
#include <vector>
#include <algorithm>

int lint_syntax_tree(const std::vector<std::vector<std::vector<int>>>& nodes) {
    if (nodes.empty()) {
        return 0;
    }
    int max_depth = 0;
    for (const auto& node : nodes) {
        max_depth = std::max(max_depth, lint_syntax_tree(node));
    }
    return 1 + max_depth;
}

int main() {
    std::vector<std::vector<std::vector<int>>> tree = {{}, {{}, {}}, {}};
    std::cout << lint_syntax_tree(tree) << std::endl;
    return 0;
}