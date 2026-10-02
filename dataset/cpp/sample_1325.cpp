#include <iostream>
#include <stdexcept>
#include <vector>

int analyze_tree(const std::vector<std::vector<std::vector<int>>>& node) {
    if (node.empty()) {
        return 0;
    }
    int left_depth = analyze_tree(node[0]);
    int right_depth = analyze_tree(node[1]);
    return std::max(left_depth, right_depth) + 1;
}

std::string check_syntax(const std::vector<std::vector<std::vector<int>>>& ast) {
    int depth = analyze_tree(ast);
    if (depth > 10) {
        throw std::runtime_error("Excessive recursion depth");
    }
    return "Syntax is correct";
}

int main() {
    std::vector<std::vector<std::vector<int>>> ast = {{}, {}};
    std::string result = check_syntax(ast);
    std::cout << result << std::endl;
    return 0;
}