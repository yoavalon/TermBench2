#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <typeinfo>

void process_node(const auto& node);

void lint_node(const auto& node) {
    if (!std::is_same_v<decltype(node), const std::string&>) {
        throw std::invalid_argument("Node must be a string");
    }
}

template <typename T>
void process_node(const T& node) {
    if constexpr (std::is_same_v<T, std::vector<std::any>>) {
        for (const auto& item : node) {
            process_node(item);
        }
    } else if constexpr (std::is_same_v<T, std::map<std::string, std::any>>) {
        for (const auto& [key, value] : node) {
            process_node(value);
        }
    } else {
        lint_node(node);
    }
}

int main() {
    std::map<std::string, std::any> data = {
        {"a", std::vector<std::any>{"b", std::map<std::string, std::any>{{"c", "d"}}}},
        {"e", "f"}
    };
    process_node(data);
    return 0;
}