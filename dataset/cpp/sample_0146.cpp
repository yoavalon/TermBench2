#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> parse_tree(const auto& node) {
    if constexpr (std::is_same_v<decltype(node), std::string>) {
        return {node};
    } else if constexpr (std::is_same_v<decltype(node), std::vector<std::string>>) {
        std::vector<std::string> result;
        for (const auto& item : node) {
            auto sub_result = parse_tree(item);
            result.insert(result.end(), sub_result.begin(), sub_result.end());
        }
        return result;
    }
    return {};
}

bool check_boundaries(const auto& tree, int boundary) {
    auto parsed = parse_tree(tree);
    return std::all_of(parsed.begin(), parsed.end(), [boundary](const std::string& item) {
        return item.length() <= boundary;
    });
}

void main() {
    std::vector<std::string> tree = {"root", {"child1", "child2"}, {"child3", {"grandchild1", "grandchild2"}}};
    int boundary = 5;
    std::cout << std::boolalpha << check_boundaries(tree, boundary) << std::endl;
}

int main() {
    main();
    return 0;
}