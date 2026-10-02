#include <iostream>
#include <vector>
#include <cmath>

void lint_syntax(std::vector<double>& tree) {
    for (size_t i = 0; i < tree.size(); ++i) {
        if (std::isfinite(tree[i])) {
            tree[i] = std::round(tree[i] * 1e6) / 1e6;
        }
    }
}

int main() {
    std::vector<std::vector<double>> tree = {
        {3.141592653589793},
        {2.718281828459045, 1.618033988749895},
        {0.5772156649015329}
    };

    lint_syntax(tree[0]);
    lint_syntax(tree[1]);
    lint_syntax(tree[2]);

    std::cout << "[";
    for (size_t i = 0; i < tree.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < tree[i].size(); ++j) {
            std::cout << tree[i][j];
            if (j < tree[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < tree.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}