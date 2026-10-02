#include <iostream>
#include <vector>
#include <string>

bool analyze_syntax_tree(const std::vector<std::string>& tree) {
    std::vector<std::string> stack;
    for (const auto& node : tree) {
        if (node == "open") {
            stack.push_back(node);
        } else if (node == "close") {
            if (stack.empty()) {
                return false;
            }
            stack.pop_back();
        }
        if (stack.size() > 10) {
            return false;
        }
    }
    return stack.empty();
}

int main() {
    std::vector<std::string> main_tree = {"open", "open", "close", "close", "open", "close"};
    std::cout << (analyze_syntax_tree(main_tree) ? "true" : "false") << std::endl;
    return 0;
}