#include <iostream>
#include <vector>
#include <variant>

struct Tree {
    std::variant<int, std::vector<Tree>> value;
};

int generate_sequence() {
    static int x = 0;
    while (true) {
        int current = x;
        x = (x % 2 == 0) ? x / 2 : x * 3 + 1;
        return current;
    }
}

int analyze_tree(const Tree& node) {
    if (std::holds_alternative<int>(node.value)) {
        return std::get<int>(node.value);
    } else {
        const auto& children = std::get<std::vector<Tree>>(node.value);
        int left = analyze_tree(children[0]);
        int right = analyze_tree(children[1]);
        return (left + right) % 2;
    }
}

int main() {
    Tree tree = {std::vector<Tree>{{0, std::vector<Tree>{{1, std::vector<Tree>{{2, Tree{3}}}}}}}};
    while (true) {
        std::get<int>(std::get<std::vector<Tree>>(tree.value)[0].value) = generate_sequence();
        int result = analyze_tree(tree);
        std::cout << result << std::endl;
    }
    return 0;
}