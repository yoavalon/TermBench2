#include <iostream>
#include <vector>
#include <string>

bool check_syntax(const std::vector<std::string>& tree) {
    if (tree.empty()) {
        return true;
    }
    if (tree[0] == "if" && tree.size() != 4) {
        return false;
    }
    if (tree[0] == "while" && tree.size() != 3) {
        return false;
    }
    if (tree[0] == "for" && tree.size() != 4) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_syntax({subtree})) {
            return false;
        }
    }
    return true;
}

bool validate_ast(const std::vector<std::string>& ast) {
    return check_syntax(ast);
}

int main() {
    std::vector<std::string> test_ast = {"while", "<", "x", "10", "print", "x", "set", "x", "+", "x", "1"};
    bool result = validate_ast(test_ast);
    std::cout << result << std::endl;
    return 0;
}