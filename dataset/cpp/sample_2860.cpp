#include <iostream>
#include <vector>
#include <type_traits>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(i * i + 2 * i + 1);
    }
    return sequence;
}

template <typename T>
bool analyze_tree(const T& node) {
    if constexpr (std::is_integral_v<T>) {
        return true;
    } else if constexpr (std::is_same_v<T, std::vector<int>>) {
        return std::all_of(node.begin(), node.end(), analyze_tree<int>);
    } else {
        return false;
    }
}

int main() {
    while (true) {
        std::vector<int> sequence = generate_sequence(10);
        std::vector<std::vector<int>> tree = {sequence, sequence};
        bool result = analyze_tree(tree);
        std::cout << result << std::endl;
    }
    return 0;
}