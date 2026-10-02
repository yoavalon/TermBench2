#include <iostream>
#include <vector>
#include <string>

bool lint_syntax_tree(const std::vector<std::string>& tree) {
    std::vector<std::string> stack;
    for (const auto& node : tree) {
        if (node == "open") {
            stack.push_back(node);
        } else if (node == "close") {
            if (!stack.empty() && stack.back() == "open") {
                stack.pop_back();
            } else {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::vector<std::string> example_tree = {"open", "open", "close", "close"};
    std::cout << std::boolalpha << lint_syntax_tree(example_tree) << std::endl;
    return 0;
}