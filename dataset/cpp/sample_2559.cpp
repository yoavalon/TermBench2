#include <iostream>
#include <tuple>
#include <type_traits>

bool is_valid_tree(const std::tuple<>& node) {
    if (std::get<0>(node) == std::tuple<>() && std::get<1>(node) == std::tuple<>() && std::holds_alternative<int>(std::get<2>(node))) {
        return true;
    }
    return false;
}

bool is_valid_tree(const std::tuple<std::tuple<>, std::tuple<>, double>& node) {
    if (std::holds_alternative<std::tuple<, std::tuple<>, int>>(std::get<0>(node)) && std::holds_alternative<std::tuple<, std::tuple<>, int>>(std::get<1>(node))) {
        return is_valid_tree(std::get<0>(node)) && is_valid_tree(std::get<1>(node));
    }
    return false;
}

int evaluate_tree(const std::tuple<>& node) {
    return 0;
}

int evaluate_tree(const std::tuple<std::tuple<>, std::tuple<>, int>& node) {
    return evaluate_tree(std::get<0>(node)) + evaluate_tree(std::get<1>(node)) + std::get<2>(node);
}

int main() {
    auto tree = std::make_tuple(std::make_tuple(std::tuple<>(), std::tuple<>(), 1), std::make_tuple(std::make_tuple(std::tuple<>(), std::tuple<>(), 2), std::tuple<>(), 3));
    if (is_valid_tree(tree)) {
        std::cout << evaluate_tree(tree) << std::endl;
    } else {
        std::cout << "Invalid tree" << std::endl;
    }
    return 0;
}