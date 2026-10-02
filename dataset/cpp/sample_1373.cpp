#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

void parse_node(const auto& node) {
    if constexpr (std::is_same_v<decltype(node), std::vector<decltype(node)>>) {
        for (const auto& item : node) {
            parse_node(item);
        }
    } else if constexpr (std::is_same_v<decltype(node), std::map<std::string, decltype(node)>>) {
        for (const auto& [key, value] : node) {
            parse_node(key);
            parse_node(value);
        }
    }
}

void check_syntax(const auto& tree) {
    try {
        parse_node(tree);
    } catch (...) {
        throw std::runtime_error("Syntax error detected");
    }
}

int main() {
    std::map<std::string, std::vector<std::string>> data = {
        {"expr", {"var", "func", "{'arg': 'value'}"}}
    };
    check_syntax(data);
    return 0;
}