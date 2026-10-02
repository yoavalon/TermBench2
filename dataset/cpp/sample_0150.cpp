#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

void validate_node(const auto& node) {
    if constexpr (std::is_same_v<decltype(node), std::vector<decltype(node)>>) {
        for (const auto& child : node) {
            validate_node(child);
        }
    } else if constexpr (std::is_same_v<decltype(node), std::map<decltype(node)::key_type, decltype(node)::mapped_type>>) {
        for (const auto& [key, value] : node) {
            validate_node(key);
            validate_node(value);
        }
    } else if constexpr (!std::is_same_v<decltype(node), int> && !std::is_same_v<decltype(node), float> &&
                         !std::is_same_v<decltype(node), std::string> && !std::is_same_v<decltype(node), bool> &&
                         !std::is_same_v<decltype(node), std::nullptr_t>) {
        throw std::invalid_argument("Invalid node type");
    }
}

std::string lint_tree(const auto& tree) {
    validate_node(tree);
    return "Tree validated";
}

int main() {
    std::vector<std::variant<int, std::map<std::string, std::variant<int, std::map<std::string, int>, std::nullptr_t>>, std::nullptr_t>> test_tree = {
        1,
        std::map<std::string, std::variant<int, std::map<std::string, int>, std::nullptr_t>>{
            {"key", "value"},
            {"nested", std::vector<std::variant<int, std::map<std::string, int>, std::nullptr_t>>{
                3,
                std::map<std::string, int>{{"deep", 4}}
            }}
        },
        std::nullptr_t{}
    };

    try {
        auto result = lint_tree(test_tree);
        std::cout << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}